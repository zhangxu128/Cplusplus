import java.awt.Graphics;
import java.awt.Rectangle;
 
 
public class Wall {
  /*ǽ����*/
  int x,y,w,h;  //λ�úͿ��
  private TankClient tc;  //����Ȩ��
   
  public Wall(int x, int y, int w, int h, TankClient tc) {
    super();
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.tc = tc;
  }
  /*��ȡǽ�ķ�Χ*/
  public Rectangle getRect(){
    return new Rectangle(x,y,w,h);
  }
  /*��ǽ*/
  public void draw(Graphics g){
    g.fillRect(x, y, w, h);
  }
}