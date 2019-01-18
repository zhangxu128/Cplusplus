import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.sql.*;
import java.util.*;
import java.util.Date;
public class Manager extends JPanel implements ActionListener
{
	JSplitPane jsp=new JSplitPane(JSplitPane.VERTICAL_SPLIT);
	private JPanel jpt=new JPanel();
	String[] str1=new String[3];
	public static String mgNo;
	String sql;
	DataBase db;
	private JLabel[] jlArray=new JLabel[]
	{
		new JLabel("       ����Ա��"),
		new JLabel("       Ȩ        ��"),
	    new JLabel("        ��       ��")   
	};
	private JTextField[] jtxtArray=new JTextField[]
	{
		new JTextField(),
		new JTextField(),
		new JTextField()
	};
	private JButton[] jbArray=new JButton[]
	{
		new JButton("��ӹ���Ա"),
		new JButton("ɾ������Ա"),
		new JButton("�޸���Ϣ"),
		new JButton("������Ϣ")
	};
	//��������
	Vector<String> head=new Vector<String>();
	{
		head.add("����Ա��");
		head.add("Ȩ��");	
		head.add("����");	
	}
	//���²��Ӵ��������ñ��
	Vector<Vector> data=new Vector<Vector>();
    //�������ģ��
    DefaultTableModel dtm=new DefaultTableModel(data,head);
    //����Jtable����
	JTable jt=new JTable(dtm);
	//��JTable��װ����������
	JScrollPane jspn=new JScrollPane(jt);
	public Manager(String mgNo)
	{
		this.setLayout(new GridLayout(1,1));
	    this.mgNo=mgNo;
		//���������ϲ���Ϊ�ղ��ֹ�����
		jpt.setLayout(null);
		//����jspt�зָ����ĳ�ʼλ��
		jsp.setDividerLocation(115);
		//���÷ָ����Ŀ��
		jsp.setDividerSize(4);
		jsp.setTopComponent(jpt);
		jsp.setBottomComponent(jspn);
		for(int i=0;i<3;i++)
		{
			jpt.add(jlArray[i]);
			jpt.add(jtxtArray[i]);	
		    jlArray[i].setBounds(15+i*250,20,100,25);
		    jtxtArray[i].setBounds(115+i*250,20,150,25);
		    jtxtArray[i].addActionListener(this);
		}
		this.add(jsp);
		//�����²��Ӵ���
    	jsp.setBottomComponent(jspn);
    	//��JButton��ӽ�jpt,���ü�����
		for(int i=0;i<4;i++)
		{
			jpt.add(jbArray[i]);
			jbArray[i].setBounds(140+120*i,70,100,25);
			jbArray[i].addActionListener(this);
		}
	    //���ô���Ĵ�Сλ�ü��ɼ���
		this.setBounds(5,5,600,500);
		this.setVisible(true);
	}
	
	public void setFlag(boolean b)
	{
		jbArray[0].setEnabled(b);
		jbArray[1].setEnabled(b);		
	}
	
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==jtxtArray[0]){jtxtArray[1].requestFocus();}//���ü���������			
		if(e.getSource()==jtxtArray[1]){jtxtArray[2].requestFocus();}//���ü���������	
		sql="select permitted from manager where mgNo='"+mgNo+"'";
		db=new DataBase();
		String string="";
		try{
			int p=0;
			if(string.equals("1")){   p++;
				String jtxt=jtxtArray[0].getText().trim();
				if(jtxt.equals("")){//������Ϊ�գ���ʾ
					JOptionPane.showMessageDialog(this,	"���������Ա��������",
						        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				    return;
				}
				if(e.getSource()==jbArray[0]){//ִ����Ӳ���
					this.insertManager();
				}
				if(e.getSource()==jbArray[1]){//ִ��ɾ������
					this.deleteManager();
				}
				if(e.getSource()==jbArray[2]){//ִ���޸Ĳ���
					this.updateManager();
				}
				if(e.getSource()==jbArray[3]){//ִ�в�ѯ����
					this.selectManager();
				}
			}
			if(p==0){ //˵���ù���Ա����ͨ����Ա��û���޸Ĺ���Ա��Ϣ��Ȩ��
				jtxtArray[0].requestDefaultFocus();
				String jtxt=jtxtArray[0].getText().trim();
				if(jtxt.equals("")){//����Ա������Ϊ�գ���ʾ
					JOptionPane.showMessageDialog(this,	"���������Ա��������",
						        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				    return;
				}
				else if(jtxt.equals(mgNo)){//�����˹���Ա��
					if(e.getSource()==jbArray[3]){//ִ��manager1����
						this.manager1();
					}
					if(e.getSource()==jbArray[2]){//ִ���޸Ĳ���
						String str[]=new String[3];
						int row = jt.getSelectedRow();
						if(row>=0){
							for(int i=0;i<3;i++){
								str[i]=jt.getValueAt(row,i).toString();
							}
							sql="update manager set password='"
							     +str[2]+"' where mgNo="+Integer.parseInt(str[0].trim());
							     
							db=new DataBase();
							int i=0;
							if(i==1){//
								JOptionPane.showMessageDialog(this,"�޸ĳɹ�����",
								                  "��Ϣ!!",JOptionPane.INFORMATION_MESSAGE);
								return;											
							}
							else{//����������ʾ
								JOptionPane.showMessageDialog(this,"�����²�������",
	                                   "Warning!!",JOptionPane.INFORMATION_MESSAGE);
								return;											
							}
						}
						else{//����������ʾ
							JOptionPane.showMessageDialog(this,"�����²�������",
	                               "Warning!!",JOptionPane.INFORMATION_MESSAGE);
							return;								
						}	
					}
				}
				else{//��ʾ��ͨ����Աû�е�Ȩ��
					JOptionPane.showMessageDialog(this,	"�㲻�ܲ鿴���˵���Ϣ,���������룡",
				        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				    return;					
				}
			}
		}
		catch(Exception ex){ex.printStackTrace();}
	}
	public void insertManager(){
		for(int i=0;i<3;i++){
		    str1[i]=jtxtArray[i].getText().trim();		
		}
		if(!str1[0].equals("")&&!str1[1].equals("")&&!str1[2].equals("")){
			if(!str1[0].matches("^\\d+$")){//�жϹ���Ա���ĸ�ʽ
				JOptionPane.showMessageDialog(this,	"����Ա��ֻ��Ϊ���֣�����",
				        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				return;							
			}
			int temp = Integer.parseInt(str1[0]);			
			sql="insert into manager(mgNo,Permitted,password) values("
			          +temp+",'"+str1[1]+"','"+str1[2]+"')";//ִ�в��빦��
			db=new DataBase();
			int j=0;
			if(j==0){//��ʾʧ����Ϣ
				JOptionPane.showMessageDialog(this,	"����ʧ�ܣ�����",
				        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				return;				
			}
			Vector<String> v=new Vector<String>();
		    for(int i=0;i<=2;i++){
				v.add(str1[i]);//��ÿ����ӵ���ʱ����v
				if(i<3){jtxtArray[i].setText("");}	
		    }
		    data.add(v);
			dtm.setDataVector(data,head);//����table	
			jt.updateUI();
			jt.repaint();
			return;
		}
		else{//����Ϊ��ʱ��ʾ
			JOptionPane.showMessageDialog(this,	"ѧ����Ϣ����Ϊ�գ�����",
						        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
						        return;	
		}
	}
	public void deleteManager(){
		String mgNo=jtxtArray[0].getText().trim();
		if(mgNo.equals("")){//Ϊ����ʾ
			JOptionPane.showMessageDialog(this,	"ѧ�Ų���Ϊ�գ�����",
						        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;			
		}
		sql="select permitted from manager where mgNo="+Integer.parseInt(mgNo);
		db=new DataBase();
		String str="";
		try{
			if(str.equals("1")){//�����ʾ��Ϣ
	        	JOptionPane.showMessageDialog(this,	"����ɾ����������Ա��Ϣ��¼����",
							        "����",JOptionPane.INFORMATION_MESSAGE);
	        	return;	
			}
			else{//ִ��ɾ��
				sql="delete from manager where mgNo="+Integer.parseInt(mgNo);
		    	db=new DataBase();
	        	JOptionPane.showMessageDialog(this,	"�ɹ�ɾ���ù���Ա��Ϣ����",
							        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			}
		}
	    catch(Exception e){e.printStackTrace();}	
	}
	public void updateManager(){
		String str[]=new String[3];
		int row = jt.getSelectedRow();
		if(row>=0){
			for(int i=0;i<3;i++){//�õ���ѡ����
				str[i]=jt.getValueAt(row,i).toString();
			}
			sql="update manager set mgNo='"+str[0]+"',permitted='"+str[1]
			   +"',password='"+str[2]+"' where mgNo="+Integer.parseInt(str[0].trim());
			db=new DataBase();
			JOptionPane.showMessageDialog(this,"�޸ĳɹ�����",
			                      "��Ϣ!!",JOptionPane.INFORMATION_MESSAGE);
			return;								
		}
		if(row==-1){//��ʾ
			JOptionPane.showMessageDialog(this,
			"����'����'��ť,���²��ı�������,��ѡ��������,���'�޸���Ϣ'��ť��",
			                         "Warning!!",JOptionPane.INFORMATION_MESSAGE);
			return;
		}		
	}
	public void selectManager(){
		if(jtxtArray[0].getText().equals("")){//��ʾ
			JOptionPane.showMessageDialog(this,"���벻��Ϊ�գ����������룡����",
			                              "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;
		}
		int q=Integer.parseInt(jtxtArray[0].getText().trim());
	   	sql="select * from manager where mgNo="+q;
	    db=new DataBase();
		this.table();   	
	}
    public void manager1(){
       	sql="select * from manager where mgNo="+Integer.parseInt(jtxtArray[0].getText().trim());
        db=new DataBase();
		this.table(); 	    	
    }
    public void table(){
    	try{
		     int k=0;
			 Vector<Vector> vtemp = new Vector<Vector>();
			 
			 if(k==0){//��manager����û�иù���Ա�ţ��������ʾ�Ի���
			 	 JOptionPane.showMessageDialog(this,"û����Ҫ���ҵ�����",
				                 "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			 }
			dtm.setDataVector(vtemp,head);
			jt.updateUI();
			jt.repaint();				 	
		}
		catch(Exception e){e.printStackTrace();}	
    }
    public static void main(String[]args)
    {
    	new Manager(mgNo);
    }
}