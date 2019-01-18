import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import javax.swing.event.*;
import java.sql.*;
import java.util.*;
import java.util.Date;
public class GuaShi extends JPanel implements ActionListener
{
	DataBase db;
	String sql;
	String str;
	//�����ָ��Ϊ���µ�JSplitePane����
    private JSplitPane jsp=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true);
    //����JPanel����
	private JPanel jpt=new JPanel();
	private JPanel jpb=new JPanel();
	//������ť����
	private JButton[] jbArray=new JButton[]
	{
		new JButton	("��ʧ"),
		new JButton	("ȷ��")
	};
	private JLabel jl=new JLabel("���������ѧ��:");

	private JTextField jtxt=new JTextField();

	//��������
	Vector<String> head = new Vector<String>();
	{
		head.add("���");
		head.add("ѧ��");
		head.add("����ʱ��");
		head.add("����ʱ��");
		head.add("�Ƿ����");
		head.add("�Ƿ�ԤԼ");
	}
	//
	Vector<Vector> data=new Vector<Vector>();
	//�������ģ��
    DefaultTableModel dtm=new DefaultTableModel(data,head);
    //����Jtable����
	JTable jt=new JTable(dtm);
	//��JTable��װ����������
	JScrollPane jspn=new JScrollPane(jt);
	public GuaShi()
	{
		this.setLayout(new GridLayout(1,1));
		//��������RetrunBook�������²��־�Ϊ�ղ��ֹ�����
		jpt.setLayout(null);
		jpb.setLayout(null);
		//����Label�Ĵ�С��λ��
           jl.setBounds(5,15,100,20);	
		//��Jlabel��ӵ�jpt�����
		 jpt.add(jl);
		//ΪJTextField���ô�С��λ��
		jtxt.setBounds(105,15,300,20);
    	//��JTextField��ӵ�jpt
	 jpt.add(jtxt);
        //����JBuuton�Ĵ�С��λ��
	    jbArray[0].setBounds(5,50,100,20);
        jbArray[1].setBounds(150,50,100,20);
        //���JButton����������¼�������
         for(int i=0;i<jbArray.length;i++)
		{
			 jpt.add(jbArray[i]);
			 jbArray[i].addActionListener(this);
		}
		//��jpt���õ�jsp���ϲ�����
    	jsp.setTopComponent(jpt);
        jsp.setBottomComponent(jspn);
    	jsp.setDividerSize(4);
    	this.add(jsp);
    	//����jsp�зָ����ĳ�ʼλ��
    	jsp.setDividerLocation(80);
		//���ô���Ĵ�Сλ�ü��ɼ���
        this.setBounds(10,10,800,600);
        this.setVisible(true); 
   	} 
   	public void actionPerformed(ActionEvent e)
   	{
   		if(e.getSource()==jbArray[1]){//�¼�ԴΪ"ȷ��"��ť
   			if(jtxt.getText().trim().equals("")){//ѧ������Ϊ�գ���ʾ
   				JOptionPane.showMessageDialog(this,"������ѧ��",
					            "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
					return;
   			}
   			else{//����ѧ�Ž��в�ѯ
   				sql="select * from RECORD where StuNO="+jtxt.getText().trim();
	   			db=new DataBase();
	   			Vector<Vector> vtemp = new Vector<Vector>();
				try{//����������쳣����
	                int k=0;
					
				    if(k==0){//��ʾ
						JOptionPane.showMessageDialog(this,"�����˴����ѧ�Ż��ѧ��û�н����¼",
						                             "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
						return;
					}			
	   			}
	   			catch(Exception ea){ea.printStackTrace();}
			}
   		}
   		if(e.getSource()==jbArray[0]){//��Ҫ��ʧͼ��
			int row=jt.getSelectedRow();
			if(row<0){
				JOptionPane.showMessageDialog(this,"��ѡ��Ҫ��ʧ����!!!","��Ϣ",
					                              JOptionPane.INFORMATION_MESSAGE);
				return;
			}
   			loseBook(row);
   			updateTable();
   		}
   	}
   		
   	public void loseBook(int row){
		String bname="";
		int lbno=0;
		int bno=Integer.parseInt((String)jt.getValueAt(row,0));//�õ���ʧ������
		String sno=(String)jt.getValueAt(row,1);//�õ���ʧ�����ѧ��
		sql="select BookName from BOOK where BookNO="+bno;
		db=new DataBase();
		
		//�ҵ����Ķ�ʧ��¼��
		sql="select MAX(LbNO) from LoseBook";
		
		sql="insert into LOSEBOOK values("+lbno+","+sno+","+bno+",'"+bname+"')";//�����¼���в����¼
		sql="select BookNo from ORDERREPORT where BookNO="+bno;//���ԤԼ�����Ƿ�ԤԼ���飬���У�ɾ��
		sql="select BookNo from EXCEEDTIME where BookNO="+bno;//��鳬�ڱ����Ƿ��и��飬���У�ɾ��
		sql="delete from RECORD where BookNO="+bno;//�ӽ�����н���ʧͼ��ļ�¼ɾ��
		sql="delete from BooK where BookNo="+bno;//��ͼ����н���ʧ����ɾ��
		int i=0;
		if(i>0){//��ʾ��ʧ�ɹ�
			JOptionPane.showMessageDialog(this,"��ϲ�㣬��ʧ�ɹ�!!!","��Ϣ",
				                           JOptionPane.INFORMATION_MESSAGE);
			return;
		}
		else{//��ʾ��ʧʧ��
			JOptionPane.showMessageDialog(this,"�Բ��𣬹�ʧʧ��!!!",
					   	"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;
		}
   	}	
   	public void updateTable(){//ʵ�ֽ����²����ĸ���
		sql="select * from RECORD where StuNO="+jtxt.getText().trim();
		db=new DataBase();
		Vector<Vector> vtemp = new Vector<Vector>();
		
		jt.clearSelection();			
		dtm.setDataVector(vtemp,head);//����table	
		jt.updateUI();
		jt.repaint();   		
   	}	
   	public int checkTime(int sno,int bno)
   	{//-1 ������û������  0����������   1��������������  -2��ʾ���ڽ�����
   		int day=0;
   		int flag=0;
   		String bname="";
   		Date now=new Date();
   		String returntime="";
   		sql="select ReturnTime from RECORD where StuNO="+sno+" and BookNO="+bno;
   		db=new DataBase();
   		
   		String[] strday=returntime.split("\\.");//����ʹ���˼򵥵�����ʽ���涨��ʱ��ĸ�ʽ
		int ryear=Integer.parseInt(strday[0].trim());
		int rmonth=Integer.parseInt(strday[1].trim());
		int rday=Integer.parseInt(strday[2].trim());
		day=(now.getYear()+1900-ryear)*365+(now.getMonth()+1-rmonth)*30+(now.getDate()-rday);
		if(day==-30)
		{//��ʾ��������
			JOptionPane.showMessageDialog(this,"�������鲻�ܻ�������",
								"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			flag=0;
		}
		else if(day>0)
		{//��������
			int i=JOptionPane.showConfirmDialog(this,"�����ѹ���,Ӧ������Ϊ"
			             +day*0.1+"Ԫ,�Ƿ���ɷ���?","��Ϣ",JOptionPane.YES_NO_OPTION);
			if(i==JOptionPane.YES_OPTION){
				JOptionPane.showMessageDialog(this,"���ѳɹ�����"+day*0.1+"Ԫ",
										"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				flag=-2;
			}
			else
			{//������û����
				flag=-1;
				sql="select BookName from BOOK where BookNO="+bno;
				sql="insert into EXCEEDTIME(StuNO,BookNO,BookName,DelayTime) values("+sno+","+bno+",'"+bname+"',"+day+")";
			}
		}
		else
		{//��ʾ���������黹����
			flag=1;
		}
		return flag;
   	}
}