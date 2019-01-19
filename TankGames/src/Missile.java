import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.util.List;
 
public class Missile {
  /*�ӵ���������*/
  Tank.Direction dir;  //�ӵ�����
  Color c;  //�ӵ���ɫ
  int x,y;  //�ӵ�λ��
  public static final int XSPEED = 15;  //�����ƶ��ٶ�
  public static final int YSPEED = 15;  //�����ƶ��ٶ�
  public static final int Whith = 10;    //�ӵ���
  public static final int Higth = 10;    //�ӵ���
  private boolean live = true;  //�ж��ӵ��Ĵ��
  private boolean good;  //�ж��ӵ�����Ӫ
   
  private TankClient tc;//����Ȩ��
   
 
  public Missile(Tank.Direction dir,Color c, int x, int y) {
    super();
      this.dir = dir;
      this.x = x;
      this.y = y;
      this.c = c;
  }
  public Missile(Tank.Direction dir,Color c, int x, int y,boolean good,TankClient tc){
    this(dir,c,x,y);
    this.good = good;
    this.tc = tc;
  }
   
  /*��ȡ�ӵ��Ĵ��*/
  public boolean isLive() {
    return live;
  }
  /*�����ӵ��Ĵ��*/
  public void setLive(boolean live) {
    this.live = live;
  }
  public void draw(Graphics g){
    /*����ӵ�����״̬������ӵ����ӵ�������ɾ��*/
    if(!live){
      tc.missiles.remove(this);  //������ɾ��
      return;
    }
    /*�ȱ���֮ǰ�Ļ�����ɫ������֮���ٻ�ԭ������ɫ*/
    Color d = g.getColor();  //��ȡ��ǰ������ɫ
    g.setColor(c);  //���û�����ɫΪ��ɫ
    /*���ӵ�*/
    g.fillOval(x, y, Whith, Higth);  
     
    g.setColor(d);  //��ԭ������ɫ
    move();  //�ƶ�
  }
   
  public void move(){
    /*�ж��ƶ������ƶ�̹��λ��*/
    switch(dir){
    case L:
      x-=XSPEED;
      break;
    case LU:
      x-=XSPEED;
      y-=YSPEED;
      break;
    case U:
      y-=YSPEED;
      break;
    case RU:
      x+=XSPEED;
      y-=YSPEED;
      break;
    case R:
      x+=XSPEED;
      break;
    case RD:
      x+=XSPEED;
      y+=YSPEED;
      break;
    case D:
      y+=YSPEED;
      break;
    case LD:
      x-=XSPEED;
      y+=YSPEED;
      break;
    case STOP:
      break;
    }
    /*�ж��ӵ���Խ��������������ӵ����������ӵ�������ɾȥ*/
    if(x<0||y<0||x>TankClient.GAME_WIDTH||y>TankClient.GAME_HEIGTH)
      live = false;
  }
  /*��ײ����ȡ�ӵ��ķ�Χ*/
  public Rectangle getRect(){
    return new Rectangle(x,y,Whith,Higth);
  }
  /*�ӵ���̹����ײ����*/
  public boolean hitTank(Tank t){
    /*����ӵ���̹����ͬһ��Χ���ӵ���̹��ͬʱ���������ӵ�ֻ��ɱ���Է�̹��*/
    if(this.live&&this.getRect().intersects(t.getRect())&&t.isLive()&&this.good!=t.isGood()){
      if(t.isGood()){ //��̹��
        /*�ҷ�̹���ӵ����л��������ֵ������ֵ0��ʱ�������*/
        t.setLife(t.getLife()-20);
        if(t.getLife()<=0) 
          t.setLive(false);
      }else{ //��̹��
        t.setLive(false);//����
      }
      this.live=false;//�ӵ�����
      tc.explode.add(new Explode(x, y, tc));//�½���ը���뼯��
      return true;
    }
    return false;
  }
  /*ѭ��̹�˼��Ϸֱ�����ж��ӵ���ײ*/
  public boolean hitTanks(List<Tank> tanks){
    for  (int i = 0; i < tanks.size(); i++){
      if(hitTank(tanks.get(i)))
        return true;
    }
    return false;
  }
  /*�ӵ���ǽ����ײ����*/
  public boolean hitWall(Wall w){
    /*����ӵ���ǽ�ķ�Χ�غ��ӵ�����*/
    if(this.live&&this.getRect().intersects(w.getRect())){
      this.live=false;  //�ӵ�����
      return true;
    }
    return false;
  }
}