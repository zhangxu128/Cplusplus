import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.util.Random;
 
 
public class Blood {
  /*Ѫ������*/
  int x, y, w, h;//Ѫ��λ�úʹ�С
  private TankClient tc;  //����Ȩ��
  private boolean live=true;//Ѫ��Ĵ��
  private static Random r = new Random();//����һ�����ֵ����
  /*��ȡѪ��Ĵ��״̬*/
  public boolean isLive() {
    return live;
  }
  /*����Ѫ��Ĵ��״̬*/
  public void setLive(boolean live) {
    this.live = live;
  }
  /*Ѫ��λ�ó�ֵ���һ����ֵ*/
  public Blood(){
    x=r.nextInt(600)+100;
    y=r.nextInt(400)+100;
    w=h=15;
  }
  /*��Ѫ��*/
  public void draw(Graphics g){
    if(!live) return;
    Color c=g.getColor();
    g.setColor(Color.magenta);
    g.fillRect(x, y, w, h);
    g.setColor(c);
  }
  /*�ͷ�Ѫ��*/
  public void fh(){
    if(!live){
      x = r.nextInt(600)+100;
      y = r.nextInt(400)+100;
      live = true;
    }
  }
  /*��ȡѪ�鷶Χ*/
  public Rectangle getRect(){
    return new Rectangle(x, y, w, h);
  }
}