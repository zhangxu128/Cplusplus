import java.awt.Color;
import java.awt.Graphics;
 
 
public class Explode {
  /*̹�˱�ը����*/
  int x,y;  //��ըλ��
  private boolean live = true;  //��ը�Ƿ����
  int step = 0;  //��ըʱ�����
  int [] diameter = new int[] {4, 7, 12, 18, 26, 32, 49, 56, 65, 77, 80, 50, 40, 30, 14, 6};//��ը��Χ
   
  private TankClient tc;  //����Ȩ��
  public Explode(int x, int y, TankClient tc) {  
    super();
    this.x = x;
    this.y = y;
    this.tc = tc;
  }
   
  /*����ը*/
  public void draw(Graphics g){
    if(!live) return;  //�����ը����״̬��������
    /*�����ըʱ�������ը�����ڲ��ڼ�����ɾ��*/
    if(step == diameter.length){
      live = false;  //��ը����
      step = 0;  //����ʱ���0
      tc.explode.remove(this);  //������ɾ��
      return;
    }
    /*����ը*/
    Color c = g.getColor();
    g.setColor(Color.orange);
    g.fillOval(x, y, diameter[step], diameter[step]);
    g.setColor(c);
     
    step++;
  }
   
}