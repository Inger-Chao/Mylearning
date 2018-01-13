###几个汇编程序

***数组排序***

```x86asm
;=====================================
; Name : 选择排序N个数据
; Func : 考试前自写上课老师写的程序
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

