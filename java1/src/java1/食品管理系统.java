package java1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
public class ʳƷ����ϵͳ {

	public static void main(String[] args) throws Exception
	{
		// TODO Auto-generated method stub
         Spgl shipin=new Spgl();
         BufferedReader sr= new BufferedReader(new InputStreamReader(System.in));
         while(true) {
        	 System.out.println("�밴������ʾѡ���ܣ�");
        	 System.out.println("���ʳƷ������1");
        	 System.out.println("����ʳƷ��Ϣ������2");
        	 System.out.println("�޸�ʳƷ�۸�������3");
        	 System.out.println("ɾ��ʳƷ������4");
        	 System.out.println("�˳�������0");
        	 
        	 String str=sr.readLine();
        	 if(str.equals("1")) {
        		 System.out.println("������ʳƷ��ţ�");
        		 String bh=sr.readLine();
        		 System.out.println("������ʳƷ���ƣ�");
        		 String mc=sr.readLine();
        		 System.out.println("������ʳƷ�۸�");
        		 float jg=Float.parseFloat(sr.readLine());
        		 Sp sp=new Sp(bh,mc,jg);
        		 shipin.addsp(sp);
        	 }
        	 else if(str.equals("2")) {
        		 System.out.println("������ʳƷ��ţ�");
        		 String bh=sr.readLine();
        		 shipin.spxx(bh);
        	 }
        	 else if(str.equals("3")) {
        		 System.out.println("������ʳƷ��ţ�");
        		 String bh=sr.readLine();
        		 System.out.println("�������µļ۸�");
        		 float jg=Float.parseFloat(sr.readLine());
        		 shipin.spjg(bh, jg);
        	 }
        	 else if(str.equals("4")) {
        		 System.out.println("������ʳƷ��ţ�");
        		 String bh=sr.readLine();
        		 shipin.del(bh);
        	 }
        	 else if(str.equals("0")) {
        		 System.out.println("��л����ʹ�ã��ټ�");
        		 System.exit(0);
        	 }
        	 else {
        		 System.out.println("��������������������������˳���");
        	 }
         }
	}

}
//����һ��ʳƷ��
class Sp{
	private String bianhao;
	private String mingcheng;
	private float jiage;
	Sp(String bianhao,String mingcheng,float jiage){
		this.bianhao=bianhao;
		this.jiage=jiage;
		this.mingcheng=mingcheng;
	}
	public String getBianhao(){
		return bianhao;
	}
	public void setBianhao(String bianhao) {
		this.bianhao=bianhao;
	}
	public String getMingcheng() {
		return mingcheng;
	}
	public void setMingcheng(String mingcheng) {
		this.mingcheng=mingcheng;
	}
	public float getJiage() {
		return jiage;
	}
	public void setJiage(float jiage) {
		this.jiage=jiage;
	}
	
}
//����һ��ʳƷ������
class Spgl{
	private ArrayList aa=null;
	Spgl(){
		aa=new ArrayList();
	}
	public void addsp(Sp sp) {
		aa.add(sp);
		System.out.println("�����ʳƷ�ɹ���");
	}
	public void spxx(String bh) {
		int i;
		for(i=0;i<aa.size();i++) {
			Sp sp=(Sp)aa.get(i);
			if(sp.getBianhao().equals(bh))
					 {
				System.out.println("��ʳƷ����ϢΪ��");
				System.out.println("��ʳƷ�ı��Ϊ��"+bh);
				System.out.println("��ʳƷ������Ϊ��"+sp.getMingcheng());
				System.out.println("��ʳƷ�ļ۸�Ϊ��"+sp.getJiage());
				break;
			}
		}
		if(i==aa.size()) {
			System.out.println("�Բ����޴���Ʒ��");
		}
	}
	public void spjg(String bh,float jg) {
		int i ;
		for(i=0;i<aa.size();i++) {
			Sp sp=(Sp)aa.get(i);
			if(sp.getBianhao().equals(bh)) {
				sp.setJiage(jg);
				System.out.println("�޸�ʳƷ�۸�ɹ���");
				break;
			}
		}
		if(i==aa.size()) {
			System.out.println("�Բ���û���ҵ���Ӧ����Ʒ��Ϣ���޸�ʧ�ܡ�");
		}
	}
	public void del(String bh){
		int i ;
		if(aa.size()==0) {
			System.out.println("�Բ��𣬲ֿ����Ѿ�û���κ���Ʒ��");
		}
		for(i=0;i<aa.size();i++) {
			Sp sp=(Sp)aa.get(i);
			if(sp.getBianhao().equals(bh)) {
				aa.remove(i);
				System.out.println("ɾ��ʳƷ�ɹ���");
				break;
			}
		}
		if( (i==aa.size()) && (aa.size()!=0) ) {
			System.out.println("�Բ���û�и�ʳƷ");
		}
	}
}