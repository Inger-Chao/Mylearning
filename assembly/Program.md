### 几个汇编程序

***数组排序***

```asm
;=====================================
; Name : 选择排序N个数据
; Func : 考试前改自写上课老师写的程序
; Param : SI：存放位置 DI：移动指针
; 076A:0000 1500 
; 076A:0002 2100
; ……
; 076A:0008 0800
; Result : 
; 076A:0000 2100
; 076A:0000 1500
; ……成功！
;=====================================
data segment
ARY DW 21,33,10,5,8
data ends
assume cs:code,ds:data
code segment
start:

	MOV SI,data 
	MOV DS,SI ;初始化DS段地址 DS=076A
	MOV SI,0 ;让SI指向第一个数组元素 SI=0000H
	MOV CX,5 ;

SORT1 PROC
	DEC CX 
	MOV DX,CX ;需要进行n-1躺循环，对CX进行保护
S1:
	MOV CX,DX ;
	LEA DI,[SI+2] ;取SI的下一个字单元的地址给DI，DI=0002,指向SI的下一个单元
	MOV AX,[SI] ;SI的值->AX
S2:
	CMP AX,[DI] ;AX和DI所指的单元作比较
	JAE S3 ;无符号数比较。若AX大于等于[DI]单元，则跳转到S3。否则顺序执行
	XCHG AX,[DI] ;把AX和[DI]单元的值交换，然后顺序执行
S3:
	ADD DI,2 ;DI指向下一个单元
	LOOP S2 ;循环S2直到CX=0

	MOV [SI],AX ;AX中为本次循环找到的最大值->SI单元指向的元素值
	ADD SI,2 ;SI指向下一个元素
	DEC DX ;DX中存的是外循环的值
	JNZ S1 ;cx!=0 转s1，否则循环结束 结束程序
SORT1 ENDP
	mov ax,4c00h
	int 21h
code ENDS
END start
```

***中断子程序设计与调试(牵扯8255A和8259)***
```asm
; Date : 2017-11-28 11:12:14
; File Name : PRAM05.ASM
; Description : 实验五 中断子程序设计与调试
; Author : Angus
; Version: V1.0

; 实验题目：
; 在试验箱上搭出发光二极管，显示二进制数，连接中断，在发光二极管上显示中断次数

;=====================================================
; Name : 中断子程序设计与调试
; Func : 发光二极管显示中断次数
; Param : 试验箱上搭出发光二极管，显示二进制数，连接中断
; Result : 在发光二极管上显示中断次数
;=====================================================

; 声明（假设）段寄存器对应的段
assume cs:code,ds:data

; 定义一些常用值为宏，程序编译时会将其用其对应的值替代（类似于c语言中的常量）
data segment 				; 定义数据段
	b_port equ 61h          ; 8255A B端口I/O地址
	t_port equ 63h		    ; 8255A 控制端口I/O地址
	e_port equ 20h		    ; 8259A 偶端口地址	
	o_port equ 21h		    ; 8259A 奇端口地址
data ends 					; 数据段结束

code segment 				; 代码段
main proc
	mov ax,0 				
	mov ds,ax 				; ds存放中断向量表的段地址（0000h），关于中断向量表在书P263

; 初始化8255A，设置其端口工作方式

	mov al,80h				; 80h(10000000B）设置8255A所有端口均为输出
	out t_port,al 	    	; 将数据送8255A控制端口

; 初始化8259A，设置其端口工作方式

	in  al,o_port 	    	; 从8259A的奇端口（21h）读取OCW1（操作命令字）
	and al,7fh				; 与后得7fh(01111111B)对应只开启IR7的中断，详细解释在书P276
	out o_port,al 		    ; 将OCW1写入8259A的奇端口

; 安装中断，设置中断向量表

	cli 					; CLI(Clear Interrupt) 中断标志置0指令，使IF=0，关中断
	lea ax,serv 			; 获取中断服务的偏移地址
	add ax,2000h			; 因装入程序时指定的偏移地址2000h，故中断服务偏移地址还需加2000h
	mov si,003ch   			; IR7对应的中断类型号为0fh，故而存放入口地址的单元在4×0fh，即3c处
	mov [si],ax 			; 存放中断服务偏移地址（两个字节）
	mov ax,0 				; 装入程序时指定了段地址为0，故中断服务程序段地址为0
	mov [si+2],ax 			; 存放中断服务段地址（两个字节）
	sti						; STI(Set Interrupt) 中断标志置1指令，使IF=1，开中断

	mov bl,0
next:
	jmp next				; 进行死循环，等待接收中断请求并响应
main endp

serv proc
	inc bl                  ; 每中断一次，bl+1
	mov al,bl 				
	not al 					; 取非，因led低电平点亮
	out b_port,al 	    	; 将数据输出到8255A的B端口，点亮led

	mov al,20h 		 		; EOI(End Of Interrupt)硬件中断结束标志，若无会一直执行中断
	out e_port,al 	     	; 规定EOI必须写入8259A偶端口，详细解释在书P267
	
	iret					; 中断返回
serv endp

code ends 					; 代码段结束
end main 					; end main表示两层意思，一是编译时指定程序入口在main，二是告知结束
```
***中断编程***
```asm
;=====================================
; Name : 当发生除法溢出时，在屏幕中间显示OVERFLOW!，返回DOS
; Func : 找到一块不用的内存将DO0传送进去0000:0200
;=====================================

assume cs:code

code segment
start:
 	;do0安装程序
	mov ax,cs
	mov ds,ax
	mov si,offset do0 ;设置ds:si指向源地址

	mov ax,0
	mov es,ax
	mov di,200h	;设置es:di指向目的地址

	mov cx,offset do0end - offset do0	;设置cx为传输长度
	cld ;设置传输方向为正
	rep movsb ;使用movsb指令将do0的代码送入0:200处

	;设置中断向量表
	mov ax,0
	mov es,ax
	mov word ptr es:[0*4],200h
	mov word ptr es:[0*4+2],0

	mov ax,1000h
	mov bh,1
	div bh

	mov ax,4c00h
	int 21h

do0:
	;显示字符串"overflow!"
	jmp short do0start
	db 'overflow!'

do0start:

	;push ax
	;push cx
	;push ds
	;push es
	;push si
	;push di

	;设置ds:si指向字符串
	mov ax,cs
	mov ds,ax
	mov si,202h ;jmp short do0start指令占2Byte

	mov ax,0b800h
	mov es,ax
	mov di,12*160+36*2 ;设置es:di指向显存空间的中间位置

	mov cx,9 ;字符串长度

s:
	mov al,[si]
	mov es:[di],al
	mov byte ptr es:[di+1],4 ;红色
	inc si
	add di,2
	loop s


	;pop di
	;pop si
	;pop es
	;pop ds
	;pop cx
	;pop ax
	;iret

	mov ax,4c00h
	int 21h
do0end:
	nop

code ends
end start
```
***8253计数器实验(安光)***
```asm
; Date : 2017-12-05 19:03:32
; File Name : PRAM08.ASM
; Description : 8253A定时器/计时器实验
; Author : Angus
; Version: V1.0


; 实验题目：
; 系统的OPCLK（1.1625MHz）作为音乐节拍，由表格查出每个音符对应的时间常数送给计数器2
;（工作方式3:方波频率发生器），以确定音调，驱动扬声器产生音乐

STACK1 SEGMENT STACK
	DW 64 DUP(?)
STACK1 ENDS

DATA SEGMENT
TABLE DB 33H,33H,3DH,33H,26H,26H, 26H, 26H, 2DH, 2DH, 26H, 2DH, 33H
DB 33H,33H,33H,33H, 33H, 4DH, 45H, 3DH, 3DH, 3DH, 45H, 4DH, 45H
DB 45H,45H,45H,45H,45H, 45H, 45H, 33H, 33H, 3DH, 33H, 26H, 26H
DB 26H,28H,2DH,2DH,26H, 26H, 33H, 33H, 33H, 33H, 45H, 3DH, 39H
DB 39H,39H,52H,4DH,4DH, 4DH, 4DH, 4DH, 4DH, 4DH, 4DH, 2DH, 2DH
DB 26H,26H,26H,26H,26H, 26H, 28H, 28H, 2DH, 28H, 26H, 26H, 26H
DB 26H,2DH,28H,26H,2DH, 2DH, 33H, 3DH, 4DH, 45H, 45H, 45H, 45H
DB 45H,45H,45H,45H,33H, 33H, 3DH, 33H, 26H, 26H, 26H, 28H, 2DH
DB 2DH,26H,2DH,33H,33H, 33H, 33H, 33H, 33H, 45H, 3DH, 39H, 39H
DB 39H,52H,4DH,4DH,4DH, 4DH, 4DH, 4DH, 4DH, 4DH, 00H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: 
	MOV AX,DATA
	MOV DS,AX ;初始化数据段
	MOV BX,OFFSET TABLE  ;TABLE存放到BX寄存器中
	MOV AL,[BX] ;音符数据字放入AL
	MOV AH,00H
A1: 
	MOV DL,25H ;写入计数初值
	MUL DL ;DL*AL->AX 用来作延时
	PUSH AX ;音符数据字入栈
	MOV AL,0B7H ;
	OUT 43H,AL ;写入方式控制字
	POP AX 
	OUT 42H,AL 
	MOV AL,AH
	OUT 42H,AL
	INC BX
	MOV AH,00H
	MOV AL,[BX]
	TEST AL,0FFH
	JZ A3
	MOV CX,77FFH
A2: 
	PUSH AX
	POP AX
	LOOP A2
	JMP A1
A3: 
	MOV BX,OFFSET TABLE
	MOV AL,[BX]
	MOV AH,00H
	JMP A1
CODE ENDS
END START
```

***递归函数与输出，看完上面在看这个大概率不考。***
```
;=====================================
; Name : 递归函数，计算S在200以内的S=1+2X3+3X4+4X5+..+N(N+1)+..=，并输出S和N。
;=====================================
DATA SEGMENT
	BUF DB 'S=1+2X3+3X4+4X5+..+N(N+1)+..=','$'
	N DB 'N=',0,0,'$'
	RES DW 4 DUP(0),'$'
DATA ENDS
CODE SEGMENT
	ASSUME CS:CODE,DS:DATA ;通过assume关键字说明寄存器与程序间的关联
START:
	MOV AX,DATA
	MOV DS,AX ;初始化DS
	LEA DX,BUF ;取BUF有效地址放到DX寄存器中
	MOV AH,09H 
	INT 21H ;打印字符串
	MOV DX,1
	MOV BL,2
NEXT:
	MOV AL,BL 
	INC BL ;BL++
	MUL BL ;BL*AL -> AX
	ADD DX,AX ;DX+AX -> AX
	CMP AX,200 ;AX与200比较
	JNA NEXT ;<=200，则跳转到NEXT继续执行NEXT
	
	MOV AX,BX
	MOV CL,11
	DIV CL
	LEA DI,N
	ADD DI,2
	ADD AL,48
	MOV [DI],AL
	INC DI
	ADD AH,48
	MOV [DI],AH
	
	MOV CX,0004H 
	LEA DI,RES ;取RES有效地址给DI
	ADD DI,03H ;DI指向RES字符串第四个单元
NEXT1:
	MOV AX,DX
	AND AX,000FH ;取AX最低四位
	CMP AL,0AH ;区分是0-9还是A-F
	JB NEXT2 ;<10是数字 跳转到NEXT2
	ADD AL,07 ; >10 AL+07 -> AL
NEXT2:
	ADD AL,30H ;AL+30H -> AL ASCII码+48转换成数字
	MOV [DI],AL ;AL的内容给DI指向的字符串单元
	DEC DI ;DI-- -> DI
	PUSH CX ;先保护cx
	MOV CL,04 ;04放进CL中，CL控制逻辑移位位数
	SHR DX,CL ;逻辑右移
	POP CX
	LOOP NEXT1 
	LEA DX,RES ;打印字符串
	MOV AH,09H 
	INT 21H
	
	LEA DX,N
	MOV AH,09H 
	INT 21H ;打印字符串


	MOV AX,4C00H ;结束程序
	INT 21H
CODE ENDS
END START
```
