import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import javax.swing.event.*;
import java.sql.*;
import java.util.*;
import java.util.Date;
public class ExceedTime extends JPanel implements ActionListener
{
	private JLabel jl=new JLabel("����������ѧ��");
	private JTextField jtf=new JTextField();//�����ı���
	private JLabel jl1=new JLabel("��������Ҫ���Ŀ���");
	private JTextField jtf1=new JTextField();
	//������ť
	private JButton jb=new JButton("����");
	private JButton jb1=new JButton("��ѯǷ��");
	public ExceedTime()
	{
		this.setLayout(null);//���ò���Ϊ�ղ���
		this.add(jl);//��JLabel��ӽ�JPanel
		this.add(jtf);//��JTextField��ӽ�JPanel
		this.add(jl1);
		this.add(jtf1);//��JTextField��ӽ�JPanel
		//��JButton��ӽ�JPanel
		this.add(jb);
		this.add(jb1);
		//�ֱ�����JLabel,JTextField,JButton�Ĵ�Сλ��
		jl.setBounds(50,30,120,20);
		jtf.setBounds(170,30,120,20);
		jl1.setBounds(50,70,120,20);
		jtf1.setBounds(170,70,120,20);
		jb.setBounds(180,110,100,25);
		//Ϊ��ť����¼�������
		jb.addActionListener(this);
		jb1.addActionListener(this);
		jb1.setBounds(50,110,100,25);
		//���ô���Ĵ�Сλ��
        this.setBounds(300,300,600,650);
        this.setVisible(true);
	}
	//Ϊ�¼����صļ��������ϴ����¼�
   	public void actionPerformed(ActionEvent e)
	{
		int day=0;//��ʼ����������
		DataBase db=new DataBase();
		String sno=(String)jtf.getText().trim();//�����ı������ݱ���
		if(sno.equals("")){//�������ѧ��Ϊ�ս�����ʾ
			JOptionPane.showMessageDialog(this,"ѧ�Ų���Ϊ��!!!",
			                "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;
		}
		if(sno.matches("\\D")){//����ѧ�Ÿ�ʽΪ�������
			JOptionPane.showMessageDialog(this,"ѧ��ֻ��Ϊ����!!!",
			                   "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;			
		}
		String sql="select DelayTime from EXCEEDTIME where StuNO="
		           +Integer.parseInt(sno);
		try{//�Խ���������쳣����
			int flag=0;
			if(flag==0){//�����Ϊ�ո�����ʾ
				JOptionPane.showMessageDialog(this,"���������û�г��ڣ�����Ҫ�����",
				                             "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				return;
			}	
		}
		catch(Exception ex){ex.printStackTrace();}
		if(e.getSource()==jb1){//�¼�ԴΪ"��ѯǷ��"��ť
    		if(day>0){//��ʾǷ����
    			JOptionPane.showMessageDialog(this,"��Ƿ��"+day*0.1+"Ԫ��",
		                                 "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
		      return;
    		}
    		else{//���û��Ƿ���ʾ
    			JOptionPane.showMessageDialog(this,"���������û�г��ڣ�����Ҫ�����",
			                               "��Ϣ",JOptionPane.INFORMATION_MESSAGE);
			return;
    		}
    	}
		else if(e.getSource()==jb){//�¼�ԴΪ"����"��ť
			if(jtf1.getText().trim().equals("")){//�ɷѽ��Ϊ�յ���ʾ
				JOptionPane.showMessageDialog(this,"������ɿ����",
										"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
				return;
			}
			int k=JOptionPane.showConfirmDialog(this,"�Ƿ�ɷ�?",
							"��Ϣ",JOptionPane.YES_NO_OPTION);
			if(k==JOptionPane.YES_OPTION){//ѡ��Ի��򣬵�ѡ��"��"ʱ������ʾ��������
				int ii=Integer.parseInt(jtf1.getText().trim());		
				if(ii<(day*0.1)){
					sql="update exceedtime set delaytime=delaytime-"+ii/0.1+" where stuNO="+Integer.parseInt(sno);
					db=new DataBase();
					int i=5;
					if(i==1){//�����Ӧ�ýɷ�������ʾ
						JOptionPane.showMessageDialog(this,"���ѳɹ�����"+ii+"Ԫ,���������"+(day*0.1-ii)+"Ԫ",
											"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
					      return;					
					}
					else{//ѡ��"��"����ʾ�ɷ�ʧ��
						JOptionPane.showMessageDialog(this,"�Բ��𣬽ɷ�ʧ��!!!",
											"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
					      return;					
					}
				}
			    else{//��ʾ�ɷѳɹ�
			      	JOptionPane.showMessageDialog(this,"���ѳɹ�����"+day*0.1+"Ԫ",
										"��Ϣ",JOptionPane.INFORMATION_MESSAGE);
					jtf.setText("");
					sql="delete from EXCEEDTIME where StuNO="+Integer.parseInt(sno);
									sql="update STUDENT set Permitted='��' where StuNO="+Integer.parseInt(sno);
				}
			}			 
		}}}
		
