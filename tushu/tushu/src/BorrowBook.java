import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.sql.*;
import java.util.*;
import java.util.Date;
public class BorrowBook extends JPanel implements ActionListener{
	//�����ָ��Ϊ���µ�JSplitePane����
      private JSplitPane jsp1=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true);
	private JPanel jp2=new JPanel();
	//������ť����
	int flag;
	String sql;
	DataBase db;
	private JButton jb2=new JButton("ȷ��");
	private JLabel jl3=new JLabel("��Ҫ���Ļ�ԤԼ�����");
	private JLabel jl4=new JLabel("����������ѧ��");
	//��jsp1����ı���
	private JTextField jtxt3=new JTextField();
	private JTextField jtxt4=new JTextField();
	//��jp2���õ�ѡ��
	private JRadioButton[] jrbArray=
    {new JRadioButton("����ͼ��",true),new JRadioButton("ԤԼͼ��")};
    private ButtonGroup bg=new ButtonGroup();
	Vector<String> head = new Vector<String>();	//��������
	{
		head.add("���");
		head.add("����");
		head.add("����");
		head.add("������");
		head.add("�Ƿ����");
		head.add("�Ƿ�ԤԼ");
	}	
	Vector<Vector> data=new Vector<Vector>();//���������������    
    DefaultTableModel dtm=new DefaultTableModel(data,head);//�������ģ��   
	JTable jt=new JTable(dtm); //����Jtable����	
	JScrollPane jspn=new JScrollPane(jt);//��JTable�Ž���������
    public BorrowBook()
    {
    	this.setLayout(new GridLayout(1,1));
    	//��jsp2���õ�jsp1���ϲ�����
    	jsp1.setTopComponent(jp2);
    	//����jsp1���²�����
    	jsp1.setBottomComponent(jspn);
    	//����jsp1��jsp2�зָ����ĳ�ʼλ��
    	jsp1.setDividerLocation(100);//���÷ָ�ؼ�λ��
    	jsp1.setDividerSize(4);//���÷ָ�ؼ����
    	jp2.setLayout(null);    	
		jb2.setBounds(380,20,100,20);//���ð�ť�Ĵ�С��λ��
    	//����ť��ӽ�JPanel
		jp2.add(jb2);
		jb2.addActionListener(this);
		//����JLabel������
    	jl3.setBounds(80,60,130,20);
    	jl4.setBounds(330,60,100,20);
    	//��JLabel��ӽ�JPanel
    	jp2.add(jl3);
    	jp2.add(jl4);	
    	jtxt3.setBounds(220,60,100,20);
    	jtxt4.setBounds(430,60,100,20);
    	jp2.add(jtxt3);
    	jp2.add(jtxt4);
    	for(int i=0;i<2;i++)
    	{
    		jrbArray[i].setBounds(70+i*150,20,150,20);
    		jp2.add(jrbArray[i]);
    		bg.add(jrbArray[i]);
    	}
    	this.add(jsp1);
    	//���ô���ı��⣬��Сλ�ü��ɼ���
        this.setBounds(10,10,800,600);
        this.setVisible(true);  
    }	
    //Ϊ�¼����صļ��������ϴ����¼�
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==jb2){
			if(jtxt4.getText().equals("")){//Ϊ����Ϊ�յ�������д���
				JOptionPane.showMessageDialog(this,"���벻��Ϊ�գ����������룡����",
				                      "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				return;
			}
			//��ѯѧ���ı�������ѧ���Ƿ������STUDENT����
           	sql="select * from STUDENT where StuNO="+Integer.parseInt(jtxt4.getText().trim());
            db=new DataBase();
			Vector<Vector> vtemp = new Vector<Vector>();
			
				if(true){
					JOptionPane.showMessageDialog(this,"�����˴����ѧ��","��Ϣ",
					                              JOptionPane.INFORMATION_MESSAGE);
				}
				else{
										
						JOptionPane.showMessageDialog(this,"ѧ����ȷ","��Ϣ",
	                              JOptionPane.INFORMATION_MESSAGE);
				}
		}}}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			