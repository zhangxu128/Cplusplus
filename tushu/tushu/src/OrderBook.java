import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.sql.*;
import java.util.*;
import java.util.Date;
public class OrderBook extends JPanel implements ActionListener{
	//�����ָ��Ϊ���µ�JSplitePane����
    private JSplitPane jsp1=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true);
	private JPanel jp2=new JPanel();
	//������ť����
	int flag;
	String sql;
	DataBase db;
	private JButton jb2=new JButton("ȷ��");
	private JLabel jl3=new JLabel("������ҪԤԼ�����");
	private JLabel jl4=new JLabel("����������ѧ��");
	//��jsp1����ı���
	private JTextField jtxt3=new JTextField();
	private JTextField jtxt4=new JTextField();
	Vector<String> head = new Vector<String>();	//��������
	{
		head.add("���");
		head.add("����");
		head.add("����");
		head.add("������");
		head.add("�Ƿ����");
		head.add("�Ƿ�ԤԼ");
	}
	//��jp3�����ñ��
	Vector<Vector> data=new Vector<Vector>();
    //�������ģ��
    DefaultTableModel dtm=new DefaultTableModel(data,head);
    //����Jtable����
	JTable jt=new JTable(dtm);
	//��JTable��װ����������
	JScrollPane jspn=new JScrollPane(jt);
    public OrderBook()
    {
    	this.setLayout(new GridLayout(1,1));
    	//��jsp2���õ�jsp1���ϲ�����
    	jsp1.setTopComponent(jp2);
    	//����jsp1���²�����
    	jsp1.setBottomComponent(jspn);
    	//����jsp1��jsp2�зָ����ĳ�ʼλ��
    	jsp1.setDividerLocation(80);
    	//����jsp1��jsp2�зָ����Ŀ��
    	jsp1.setDividerSize(4);
    	//����jp1��jp2Ϊ�ղ��ֹ�����
    	jp2.setLayout(null);
    	//���ð�ť�Ĵ�С��λ��
		jb2.setBounds(500,30,60,20);
    	//����ť��ӽ�JPanel
		jp2.add(jb2);
		jb2.addActionListener(this);
		//����JLabel������
    	jl3.setBounds(30,30,120,20);
    	jl4.setBounds(280,30,95,20);
    	//��JLabel��ӽ�JPanel
    	jp2.add(jl3);
    	jp2.add(jl4);	
    	jtxt3.setBounds(155,30,100,20);
    	jtxt4.setBounds(380,30,100,20);
    	jp2.add(jtxt3);
    	jp2.add(jtxt4);
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