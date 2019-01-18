import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.sql.*;
import java.util.*;
import java.util.Date;
public class BookManage extends JPanel implements ActionListener
{
	private JSplitPane jsp=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true);
	private JPanel jpt=new JPanel();
	String []str1=new String [7];
	String sql; 
	DataBase db;
	private JLabel[] jlArray=new JLabel[]
	{
		new JLabel("         ��    ��"),
		new JLabel("         ��    ��"),
		new JLabel("         ��    ��"),
		new JLabel("         �� �� ��"),
		new JLabel("         ��������"),
		new JLabel("         �� Ԥ Լ"),
		new JLabel("         �� �� ��")
	};
	private JTextField[] jtxtArray=new JTextField[]
	{
		new JTextField(),
		new JTextField(),
		new JTextField(),
		new JTextField(),
		new JTextField()
	};
	//����JButton��ť���ı�
	private JButton[] jbArray=
	{
	    new JButton("ͼ�����"),
	    new JButton("ɾ��ͼ��"),
	    new JButton("�޸�ͼ���¼"),
	    new JButton("����ͼ��")
	};
	//��������
	Vector<String> head = new Vector<String>();
	{
		head.add("���");
		head.add("����");
		head.add("����");
		head.add("������");
		head.add("��������");
		head.add("�Ƿ����");
		head.add("�Ƿ�ԤԼ");
	}
	//���²��Ӵ��������ñ��
	Vector<Vector> data=new Vector<Vector>();
    //�������ģ��
    DefaultTableModel dtm=new DefaultTableModel(data,head);
    //����Jtable����
	JTable jt=new JTable(dtm);
	//��JTable��װ����������
	JScrollPane jspn=new JScrollPane(jt);
	//������ʾ�����б������ģ�͵��ַ�������
	private String[] str={"��","��"};
	//���������б��
	private JComboBox jcp1=new JComboBox(str);
	private JComboBox jcp2=new JComboBox(str);
	public BookManage()
	{
		this.setLayout(new GridLayout(1,1));
		//���������ϲ���Ϊ�ղ��ֹ�����
		jpt.setLayout(null);
		//����jspt�зָ����ĳ�ʼλ��
		jsp.setDividerLocation(140);
		//���÷ָ����Ŀ��
		jsp.setDividerSize(4);
		jsp.setTopComponent(jpt);
		jsp.setBottomComponent(jspn);
		for(int i=0;i<5;i++)
		{
			jpt.add(jtxtArray[i]);
		}
		for(int i=0;i<7;i++)
		{
			jpt.add(jlArray[i]);
			if(i<3)
			{
			    jlArray[i].setBounds(15,10+30*i,100,20);
			    jtxtArray[i].setBounds(115,10+30*i,150,20);
	
			}
			else if(i>2&&i<5)
			{
				jlArray[i].setBounds(265,10+30*(i-3),100,20);
				jtxtArray[i].setBounds(375,10+30*(i-3),120,20);
			}
			else
			{
				jlArray[i].setBounds(495,10+30*(i-5),100,20);	
			}	
		}
		for(int i=0;i<5;i++)
		{
			jtxtArray[i].addActionListener(this);
		}
		this.add(jsp);
		jpt.add(jcp1);
		jpt.add(jcp2);
		//�����²��Ӵ���
    	jsp.setBottomComponent(jspn);
		jcp1.setBounds(595,10,100,20);
		jcp2.setBounds(595,40,100,20);
		//��JButton��ӽ�jpt
		for(int i=0;i<4;i++)
		{
			jpt.add(jbArray[i]);
			jbArray[i].setBounds(150+112*i,100,112,25);
		}
		//���ü�����
		for(int i=0;i<4;i++)
		{
			jbArray[i].addActionListener(this);
		}		
		//���ô���Ĵ�Сλ�ü��ɼ���
		this.setBounds(5,5,600,500);
		this.setVisible(true);
	}
    public void actionPerformed(ActionEvent e){
    	//������꽹��
		if(e.getSource()==jtxtArray[0]){
			jtxtArray[1].requestFocus();
		}
    	if(e.getSource()==jtxtArray[1]){
    		jtxtArray[2].requestFocus();
    	}
    	if(e.getSource()==jtxtArray[2]){
    		jtxtArray[3].requestFocus();
    	}
    	if(e.getSource()==jtxtArray[3]){
    		jtxtArray[4].requestFocus();
    	}
		if(e.getSource()==jbArray[0]){//���ͼ��
			this.insertBook();
		} 
	    if(e.getSource()==jbArray[1]){//�����Ϊ��ſ��������ɾ��
	    	this.deleteBook();
	    	}	
	    if(e.getSource()==jbArray[2]){//�����Ϊ��ſ������Ϣ�����޸�
	    	this.updateBook();
	    }	
	    if(e.getSource()==jbArray[3]){//��ѯͼ����Ϣ
	    	this.searchBook();
	    }
	}
    public void insertBook(){
		for(int i=0;i<5;i++){//�����������
            str1[i]=jtxtArray[i].getText().trim();		
		}
		if(str1[0].equals("")&&str1[1].equals("")&&str1[2].equals("")
			   &&str1[3].equals("")&&str1[4].equals("")){//������Ϊ�ս�����ʾ
			JOptionPane.showMessageDialog(this,	"ͼ����Ϣ����Ϊ�գ�����",
						        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
	            return;	
		}
	    if(!str1[0].equals("")&&!str1[1].equals("")&&!str1[2].equals("")
		   &&!str1[3].equals("")&&!str1[4].equals("")){//��ͼ����Ϣ����Book��
			str1[5]=jcp1.getSelectedItem().toString();
			str1[6]=jcp2.getSelectedItem().toString();
			sql="insert into BOOK values('"+str1[0]+"','"+str1[1]+"','"
			 + str1[2] + "',' "+str1[3]+"','"+
			            str1[4]+"','"+str1[5]+"','"+str1[6]+"')";
			db=new DataBase();
			Vector<String> v = new Vector<String>();
		    for(int i=1;i<=7;i++){//��ÿ����ӵ���ʱ����v
				v.add(str1[i-1]);	
		    }
		    data.add(v);
			dtm.setDataVector(data,head);//����table	
			jt.updateUI();
			jt.repaint();
			return;
		}
    }		
	public void deleteBook(){
		String bookno = jtxtArray[0].getText().trim();
		if(bookno.equals("")){//���������Ϊ�գ���ʾ
			JOptionPane.showMessageDialog(this,	"��Ų���Ϊ�գ�����",
						        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;			
		}
		sql="select * from RECORD where BookNO="+Integer.parseInt(bookno);
		db=new DataBase();
		sql="delete from book where BookNO="+Integer.parseInt(bookno);
	}
	public void updateBook(){
		String bookno = jtxtArray[0].getText().trim();
		if(bookno.equals("")){//���������Ϊ��ʱ��������ʾ
			JOptionPane.showMessageDialog(this,	"��������Ҫ������Ϣͼ�����ţ�",
						               "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;			
		}
		else{//��������ź�����
		    for(int i=0;i<5;i++){//�����ı�������ı���
                str1[i]=jtxtArray[i].getText().trim();		
		    }
			db=new DataBase();
			int i=0;
			int flag=0;
			int b=Integer.parseInt(bookno);
			if(!str1[1].equals("")){i=i+1;}
			if(!str1[2].equals("")){i=i+2;}
			if(!str1[3].equals("")){i=i+4;}
			if(!str1[4].equals("")){i=i+8;}
			switch(i){//����ϸ���switch���
				case 0:
					JOptionPane.showMessageDialog(this,"��Ϣ����Ϊ�գ�����",
					                     "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				break;
				case 1:
				sql="update BOOK set BookName='"+str1[1]+"' where BookNO="+b;
				db=new DataBase();
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                       "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 2:
		        sql="update BOOK set Author='"+str1[2]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                     "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 3:
		        sql="update BOOK set BookName='"+str1[1]+"',"+"Author='"
		                      +str1[2]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 4:
		        sql="update BOOK set Publishment='"+str1[3]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                      "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 5:
		        sql="update BOOK set BookName='"+str1[1]+"',"+"Publishment='"
		                        +str1[3]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                     "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 6:
		        sql="update BOOK set Author='"+str1[2]+"',"+"Publishment='"
		                      +str1[3]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                       "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 7:
		        sql="update BOOK set BookName='"+str1[1]+"',"+"Author='"+str1[2]
		                       +"',"+"Publishment='"+str1[3]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                      "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 8:
		        sql="update BOOK set BuyTime='"+str1[4]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 9:
		        sql="update BOOK set BookName='"+str1[1]+"',"+"BuyTime='"
		                +str1[4]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                     "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 10:
		        sql="update BOOK set Author='"+str1[2]+"',"+"BuyTime='"
		                  +str1[4]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                      "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 11:
		        sql="update BOOK set BookName='"+str1[1]+"',"+"Author='"+str1[2]
		             +"',"+"BuyTime='"+str1[4]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                        "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 12:
		        sql="update BOOK set Publishment='"+str1[3]+"',"+"BuyTime='"
		                        +str1[4]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                       "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 13:
		        sql="update BOOK set BookName='"+str1[1]+"',"+"Publishment='"+str1[3]
		                       +"',"+"BuyTime='"+str1[4]+"' where BookNO="+b;
		       if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                      "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 14:
		        sql="update BOOK set Author='"+str1[1]+"',"+"Publishment='"+str1[2]
		                        +"',"+"BuyTime='"+str1[4]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                       "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
		        case 15:
		        sql="update BOOK set BookName='"+str1[1]+"',"+"Author='"+str1[2]+"',"+
		            "Publishment='"+str1[3]+"',"+"BuyTime='"+str1[4]+"' where BookNO="+b;
		        if(flag>0){
					JOptionPane.showMessageDialog(this,"��ϲ�㣬�޸ĳɹ�!!!",
					                              "��Ϣ",JOptionPane.INFORMATION_MESSAGE);		        	
		        }break;
			}	
		}
	}
	public void searchBook(){//������ʾ�Ի���
		JOptionPane.showMessageDialog(this,	"������ߴ��ڵ� '��ѯͼ��' ��ť����",
						        "ǿ���Ƽ�",JOptionPane.INFORMATION_MESSAGE);	
	    return;
	}	
}