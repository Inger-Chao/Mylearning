package Singleton;

public class Test {
	public static void main(String[] args){
		Company cp = new Company();
		//CEO����ֻ��ͨ��getCeo������ȡ��
		Staff ceo1 = CEO.getCeo();
		Staff ceo2 = CEO.getCeo();
		cp.addStaff(ceo1);
		cp.addStaff(ceo2);
		//ͨ��new����VP����
		Staff v1 = new VP();
		Staff v2 = new VP();
		//ͨ��new ����Staff����
		Staff staff1 = new Staff();
		Staff staff2 = new Staff();
		Staff staff3 = new Staff();
		
		
		cp.addStaff(v1);
		cp.addStaff(v2);
		cp.addStaff(staff1);
		cp.addStaff(staff2);
		cp.addStaff(staff3);
		
		cp.showAllStaffs();
	}

}
