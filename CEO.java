package Singleton;

//CEO,��������ģʽ
public class CEO extends Staff{
	private static final CEO mCeo = new CEO();
	//���캯��˽��
	private CEO(){
	}
	
	//���еľ�̬���������Ⱪ¶��ȡ��������Ľӿ�
	public static CEO getCeo(){
		return mCeo;
	}
	
	public void work(){
		//����VP
	}
}
