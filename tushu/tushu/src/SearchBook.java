import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import javax.swing.event.*;
import java.sql.*;
import java.util.*;
import java.util.Date;
public class SearchBook extends JPanel implements ActionListener{
	int flag;
	String sql;
	DataBase db;
   //�����ָ��Ϊ���µ�JSplitePane����
    private JSplitPane jsp=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true);
	private JPanel jpt=new JPanel();//����JPanel����
	private JPanel jpb=new JPanel();
	//������ʾ�����б������ģ�͵��ַ�������
	private String[] str={"����","������","����","����ʱ��"};
	private JComboBox jcb=new JComboBox(str);//���������б��
	private JButton jb=new JButton("�ύ");	//������ť
	private JLabel[] jlArray=new JLabel[]{
		new JLabel("       ��    ��"),
		new JLabel("     ��    ��"),
		new JLabel("������")
	};	
	private JTextField[] jtxtArray=new JTextField[]{//�����ı���
		new JTextField(),new JTextField(),
	    new JTextField(),new JTextField()
	};
	private JRadioButton[] jrbArray={//������ѡ��ť
		new JRadioButton("�򵥲�ѯ",true),
		new JRadioButton("�߼���ѯ")
	};	
	private ButtonGroup bg=new ButtonGroup();//������ť��
	Vector<String> head = new Vector<String>();
	{//�����ͷ
		head.add("���");head.add("����");
		head.add("����");head.add("������");
		head.add("����ʱ��");head.add("�Ƿ����");
		head.add("�Ƿ�ԤԼ");
	}
	Vector<Vector> data=new Vector<Vector>();//�������������Ļ�����Ϣ
    DefaultTableModel dtm=new DefaultTableModel(data,head);	//�������ģ��
	JTable jt=new JTable(dtm); //����Jtable����
	JScrollPane jspn=new JScrollPane(jt);//��JTable��װ����������
	public SearchBook(){
		this.setLayout(new GridLayout(1,1));//���ò�ѯͼ�����Ϊ���񲼾�
		//��������RetrunBook�������²��־�Ϊ�ղ��ֹ�����
		jpt.setLayout(null);
		jpb.setLayout(null);
		//���õ�ѡ��Ĵ�С��λ�ã�������¼�������
		jpt.add(jcb);
		jcb.setBounds(160,20,150,20);	
	    jcb.addActionListener(this);
        //���JButton�������Сλ�ò�����¼�������
		jpt.add(jb);
		jb.setBounds(560,20,120,20);
		jb.addActionListener(this);
		for(int i=0;i<2;i++){//�Ե�ѡ��ť��������
			jrbArray[i].setBounds(20,20+i*40,100,20);
			jpt.add(jrbArray[i]);
			jrbArray[i].addActionListener(this);
			bg.add(jrbArray[i]);
		}
		for(int i=0;i<3;i++){//���ñ�ǩ���ı�������꣬��������ӽ�JPanel
			jlArray[i].setBounds(120+i*200,60,80,20);
			jtxtArray[i].setBounds(200+i*180,60,120,20);
			jpt.add(jtxtArray[i]);	
			jpt.add(jlArray[i]);
		}
		for(int i=0;i<3;i++){//�����ı���Ϊ������
			jtxtArray[i].setEditable(false);
		}
    	//�����ı��������,����ӽ�jpt
		jtxtArray[3].setBounds(350,20,120,20);
		jpt.add(jtxtArray[3]);
        jsp.setTopComponent(jpt);//��jpt���õ�jsp���ϲ�����
        jsp.setBottomComponent(jspn);
        jsp.setDividerSize(4);
       	this.add(jsp);
    	jsp.setDividerLocation(100);//����jsp�зָ����ĳ�ʼλ��
		//���ô���Ĵ�Сλ�ü��ɼ���
        this.setBounds(3,10,600,400);
        this.setVisible(true);
	}
    //Ϊ�¼����صļ��������ϴ����¼�
	public void actionPerformed(ActionEvent e){
        if(jrbArray[0].isSelected()){//"�򵥲�ѯ"��ѡ��ť��ѡ��
        	jtxtArray[3].setEditable(true);
        	for(int i=0;i<jtxtArray.length-1;i++){//�����ı���Ϊ���ɱ༭
        		jtxtArray[i].setEditable(false);
        	}
        	if(jcb.getSelectedIndex()>=0&&jcb.getSelectedIndex()<4){
		    	jtxtArray[3].requestFocus();	    
			    if(e.getSource()==jb){//����¼�ԴΪ"�ύ"��ť����ִ�м���
					String str=jtxtArray[3].getText().trim();
					if(str.equals("")){
						JOptionPane.showMessageDialog(this,"�������Ҫ����Ϣ������",
										"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
						return;
					}
				    if(jcb.getSelectedIndex()==0){//�����������в�ѯ
						sql="select * from BOOK where BookName='"+str+"'";
			        	jtxtArray[3].setText("");
					}
					else if(jcb.getSelectedIndex()==1){//���ݳ�������в�ѯ
						sql="select * from BOOK where Publishment='"+str+"'";
						jtxtArray[3].setText("");
					}
					else if(jcb.getSelectedIndex()==2){//�������߽��в�ѯ
						sql="select * from BOOK where Author='"+str+"'";
						jtxtArray[3].setText("");
					}
					else{//���ݹ���ʱ����в�ѯ
						sql="select * from BOOK where BuyTime='"+str+"'";
						jtxtArray[3].setText("");
					}
					db=new DataBase();;
					//�ӱ��м����ɹ��󣬰Ѳ鵽�����������Ϣ��ʾ�ڽ����²��ֵı���
					Vector<Vector> vtemp = new Vector<Vector>();
								
					dtm.setDataVector(vtemp,head);	//����table	
					jt.updateUI();
					jt.repaint();								
				}
	        }
        }
		if(jrbArray[1].isSelected()){//"�߼���ѯ"��ѡ��ť��ѡ��
			 jtxtArray[0].requestFocus(); //������뽹��
			 jtxtArray[3].setEditable(false);
           	 for(int i=0;i<jtxtArray.length-1;i++){//���߼���ѯ���漰���ı�����Ϊ�ɱ༭
        		jtxtArray[i].setEditable(true);
        	 }
			 if(e.getSource()==jb){//���"�ύ"��ť
			 	int bz=this.seniorSearch();
			 	if(bz!=0){return;}
			 	db=new DataBase();
				//�ӱ��м����ɹ��󣬰Ѳ鵽�����������Ϣ��ʾ�ڽ����²��ֵı���     
				Vector<Vector> vtemp = new Vector<Vector>();
				dtm.setDataVector(vtemp,head);//����table
				jt.updateUI();
				jt.repaint();							
			 } 	
		}    
	}
	public int seniorSearch(){
		int flag=0;//���ñ�־λ
		String str0=jtxtArray[0].getText().trim();
		String str1=jtxtArray[1].getText().trim();
		String str2=jtxtArray[2].getText().trim();
		if(str0.equals("")&&str1.equals("")&&str2.equals("")){//�ı�������Ϊ��
			JOptionPane.showMessageDialog(this,"�������Ҫ����Ϣ������",
								"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			flag++;
		}
		if(((!str0.equals(""))&&(str1.equals(""))&&(str2.equals("")))
		     ||((str0.equals(""))&&(!str1.equals(""))&&(str2.equals("")))
		     ||((str0.equals(""))&&(str1.equals(""))&&(!str2.equals("")))){
			JOptionPane.showMessageDialog(this,"��ʹ�ü򵥲�ѯ������",
								"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			flag++;
		}
        if((!str0.equals(""))&&(!str1.equals(""))&&(str2.equals(""))){//�������������
			sql="select * from BOOK where BookName='"+str0+"' and Author='"+str1+"'";
			jtxtArray[0].setText("");jtxtArray[1].setText("");
		}
		if((!str0.equals(""))&&(str1.equals(""))&&(!str2.equals(""))){//�����ͳ��������
			sql="select * from Book where BookName='"+str0+"' and Publishment='"+str2+"'";
			jtxtArray[0].setText("");jtxtArray[2].setText("");
		}
		if((str0.equals(""))&&(!str1.equals(""))&&(!str2.equals(""))){//��������������
			sql="select * from Book where Author='"+str1+"' and Publishment='"+str2+"'";
			jtxtArray[1].setText("");jtxtArray[2].setText("");
		}
		if((!str0.equals(""))&&(!str1.equals(""))&&(!str2.equals(""))){//�������
			sql="select * from Book where BookName='"+str0
						+"' and Publishment='"+str2+"' and Author='"+str1+"'";
			jtxtArray[0].setText("");jtxtArray[1].setText("");jtxtArray[2].setText("");
		}
		return flag;
	}
}