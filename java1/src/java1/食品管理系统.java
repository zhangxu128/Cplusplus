package java1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
public class 食品管理系统 {

	public static void main(String[] args) throws Exception
	{
		// TODO Auto-generated method stub
         Spgl shipin=new Spgl();
         BufferedReader sr= new BufferedReader(new InputStreamReader(System.in));
         while(true) {
        	 System.out.println("请按以下提示选择功能：");
        	 System.out.println("添加食品请输入1");
        	 System.out.println("查找食品信息请输入2");
        	 System.out.println("修改食品价格请输入3");
        	 System.out.println("删除食品请输入4");
        	 System.out.println("退出请输入0");
        	 
        	 String str=sr.readLine();
        	 if(str.equals("1")) {
        		 System.out.println("请输入食品编号：");
        		 String bh=sr.readLine();
        		 System.out.println("请输入食品名称：");
        		 String mc=sr.readLine();
        		 System.out.println("请输入食品价格：");
        		 float jg=Float.parseFloat(sr.readLine());
        		 Sp sp=new Sp(bh,mc,jg);
        		 shipin.addsp(sp);
        	 }
        	 else if(str.equals("2")) {
        		 System.out.println("请输入食品编号：");
        		 String bh=sr.readLine();
        		 shipin.spxx(bh);
        	 }
        	 else if(str.equals("3")) {
        		 System.out.println("请输入食品编号：");
        		 String bh=sr.readLine();
        		 System.out.println("请输入新的价格：");
        		 float jg=Float.parseFloat(sr.readLine());
        		 shipin.spjg(bh, jg);
        	 }
        	 else if(str.equals("4")) {
        		 System.out.println("请输入食品编号：");
        		 String bh=sr.readLine();
        		 shipin.del(bh);
        	 }
        	 else if(str.equals("0")) {
        		 System.out.println("感谢您的使用，再见");
        		 System.exit(0);
        	 }
        	 else {
        		 System.out.println("输入有误，您可以重新输入或者退出。");
        	 }
         }
	}

}
//创建一个食品类
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
//创建一个食品管理类
class Spgl{
	private ArrayList aa=null;
	Spgl(){
		aa=new ArrayList();
	}
	public void addsp(Sp sp) {
		aa.add(sp);
		System.out.println("添加新食品成功！");
	}
	public void spxx(String bh) {
		int i;
		for(i=0;i<aa.size();i++) {
			Sp sp=(Sp)aa.get(i);
			if(sp.getBianhao().equals(bh))
					 {
				System.out.println("该食品的信息为：");
				System.out.println("该食品的编号为："+bh);
				System.out.println("该食品的名称为："+sp.getMingcheng());
				System.out.println("该食品的价格为："+sp.getJiage());
				break;
			}
		}
		if(i==aa.size()) {
			System.out.println("对不起，无此商品！");
		}
	}
	public void spjg(String bh,float jg) {
		int i ;
		for(i=0;i<aa.size();i++) {
			Sp sp=(Sp)aa.get(i);
			if(sp.getBianhao().equals(bh)) {
				sp.setJiage(jg);
				System.out.println("修改食品价格成功！");
				break;
			}
		}
		if(i==aa.size()) {
			System.out.println("对不起，没有找到相应的物品信息，修改失败。");
		}
	}
	public void del(String bh){
		int i ;
		if(aa.size()==0) {
			System.out.println("对不起，仓库中已经没有任何物品。");
		}
		for(i=0;i<aa.size();i++) {
			Sp sp=(Sp)aa.get(i);
			if(sp.getBianhao().equals(bh)) {
				aa.remove(i);
				System.out.println("删除食品成功！");
				break;
			}
		}
		if( (i==aa.size()) && (aa.size()!=0) ) {
			System.out.println("对不起，没有该食品");
		}
	}
}