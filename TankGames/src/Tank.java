import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.util.List;
import java.util.Random;
 
import javax.swing.ImageIcon;
 
 
public class Tank {
  /*̹�˱�������*/
  int x, y;//̹������
  private int oldX, oldY;  //̹����һ������
  public static final int Whith = 30;  //̹�˿�
  public static final int Higth = 30;  //̹�˸�
  public static final int XSPEED = 5;  //�����ƶ��ٶ�
  public static final int YSPEED = 5;  //�����ƶ��ٶ�
  private Color color;  //̹����ɫ
  private boolean bL=false, bU=false, bR=false, bD=false;  //�ĸ��������ֵ
  enum Direction {L, LU, U, RU, R, RD, D, LD, STOP};  //���ĸ�����ֵ�ϳɰ˸�������ƶ�
  private Direction dir = Direction.STOP;  //��������
  private Direction ptDir = Direction.D;  //��Ͳ��ʼ���� 
  private boolean good;  //�ж�̹�˵���Ӫ
  private boolean live = true;  //�ж�̹���Ƿ���
  private static Random r = new Random();//����һ�����ֵ����
  private static int step = r.nextInt(12)+3;  //�з�̹������ƶ�����3-14��
  private int Life = 100;  //Ѫ��
  private BloodBar bb = new BloodBar();  //Ѫ����
   
//  ImageIcon icon = new ImageIcon("res\\myTank.jpg");
//  ImageIcon icon2 = new ImageIcon("res\\enemyTank.jpg");
//  Image image = icon.getImage();
//  Image image2 = icon2.getImage();
   
   
  private TankClient tc;  //����Ȩ��
 
  public Tank(int x, int y, boolean good, Color color) {
    super();
    this.x = x;
    this.y = y;
    this.color = color;
    this.good = good;
  }
  public Tank(int x, int y, boolean good,Color color,Direction dir,TankClient tc){
    this(x,y,good,color);
    this.dir = dir;
    this.tc = tc;
  }
  /*��ȡ̹������ֵ*/
  public int getLife() {
    return Life;
  }
  /*����̹������ֵ*/
  public void setLife(int Life) {
    this.Life = Life;
  }
 
  /*��ȡ̹����Ӫ*/
  public boolean isGood() {
    return good;
  }
  /*����̹����Ӫ*/
  public void setGood(boolean good) {
    this.good = good;
  }
  /*��ȡ̹�˴��״̬*/
  public boolean isLive() {
    return live;
  }
  /*����̹�˴��״̬*/
  public void setLive(boolean live) {
    this.live = live;
  }
  /*��̹��*/
  public void draw(Graphics g){
    if(!live){  
      if(!good){
        tc.tanks.remove(this);  //�з�̹������ʱ�ڼ�����ɾ��
        //tc.tanks.add(new Tank(r.nextInt(700),r.nextInt(500),false,Color.blue,Direction.D,this.tc));
      }
      return;
    }
    /*�ȱ���֮ǰ�Ļ�����ɫ������֮���ٻ�ԭ������ɫ*/
    Color c = g.getColor();  //��ȡ��ǰ������ɫ
    g.setColor(color);  //���û�����ɫΪ��ɫ
    /*��̹��*/
    g.fillOval(x, y, Whith, Higth);
    /*���ַ������Ƶ���̹�ˣ�����֮ǰ�����ͼƬ������ɫ����*/
//    if(good)
//      g.drawImage(image, x, y,Whith,Higth,null);
//    else
//      g.drawImage(image2, x, y, Whith, Higth, null);
    if(good)  
      bb.draw(g);  //�ҷ�̹�˻�Ѫ��
    g.setColor(Color.black);
    /*ͨ����Ͳ���򻭳���Ͳ*/
    switch(ptDir){
    case L:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x, y+Tank.Higth/2);
      break;
    case LU:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x, y);
      break;
    case U:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x+Tank.Whith/2, y);
      break;
    case RU:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x+Tank.Whith, y);
      break;
    case R:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x+Tank.Whith, y+Tank.Higth/2);
      break;
    case RD:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x+Tank.Whith, y+Tank.Higth);
      break;
    case D:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x+Tank.Whith/2, y+Tank.Higth);
      break;
    case LD:
      g.drawLine(x+Tank.Whith/2, y+Tank.Higth/2, x, y+Tank.Higth);
      break;
    }
    g.setColor(c);  //��ԭ������ɫ
    move();//�ƶ�
  }
   
  /*���̼���������*/
  public void KeyPressed(KeyEvent e){
    int key = e.getKeyCode();  //�����̼���������������������
    /*�����ƶ�̹��*/
    switch(key){
    /*�ƶ�����*/
    case KeyEvent.VK_UP:
      bU=true;
      break;
    case KeyEvent.VK_DOWN:
      bD=true;
      break;
    case KeyEvent.VK_RIGHT:
      bR=true;
      break;
    case KeyEvent.VK_LEFT:
      bL=true;
      break;
    }
    locateDirection();
  }
   
  /*���̼�����̧���*/
  public void keyReleased(KeyEvent e){
    int key = e.getKeyCode();  //�����̼���������������������
    /*�����ƶ�̹��*/
    switch(key){
    case KeyEvent.VK_UP:
      bU=false;
      break;
    case KeyEvent.VK_DOWN:
      bD=false;
      break;
    case KeyEvent.VK_RIGHT:
      bR=false;
      break;
    case KeyEvent.VK_LEFT:
      bL=false;
      break;
    case KeyEvent.VK_Z:  //�����ӵ�
      if(live)
        fire();
      break;
    case KeyEvent.VK_F2:  //�ҷ�����
      if(!this.live){
        this.live=true;
        this.setLife(100);
      }
      break;
    case KeyEvent.VK_F3:  //�з�����
      fuhuo();
      break;
    case KeyEvent.VK_A:    //�޵е���
      superFire();
      break;
    case KeyEvent.VK_Q:    //��Ѫ
      if(this.live)
        this.Life = 100;
      break;
    case KeyEvent.VK_E:    //�ͷ�Ѫ��
      tc.b.fh();
      break;
    /*��ԭλ�ü�*/
    case KeyEvent.VK_R:
      x = 50;
      y = 50;
      break;
    }
    locateDirection();  //�ϳɷ���
  }
  /*�ϳ��ƶ�����*/
  void locateDirection(){
    if(bL&&!bU&&!bR&&!bD) dir=Direction.L;
    else if(bL&&bU&&!bR&&!bD) dir=Direction.LU;
    else if(!bL&&bU&&!bR&&!bD) dir=Direction.U;
    else if(!bL&&bU&&bR&&!bD) dir=Direction.RU;
    else if(!bL&&!bU&&bR&&!bD) dir=Direction.R;
    else if(!bL&&!bU&&bR&&bD) dir=Direction.RD;
    else if(!bL&&!bU&&!bR&&bD) dir=Direction.D;
    else if(bL&&!bU&&!bR&&bD) dir=Direction.LD;
    else if(!bL&&!bU&&!bR&&!bD) dir=Direction.STOP;
  }
   
  void move(){ //�ƶ�
    /*��¼��һ����λ��*/
    oldX = x;
    oldY = y;
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
    /*�ж�̹���ƶ�Խ���������Ϸ�߽磩*/
    if(x < 5)  x = 5;
    if(y < 25)  y = 25;
    if(x+Whith > tc.GAME_WIDTH-5)  x = tc.GAME_WIDTH-Whith-5;
    if(y+Higth > tc.GAME_HEIGTH-5) y = tc.GAME_HEIGTH-Higth-5;
     
    if(dir != Direction.STOP)  //���̹�˲���ֹ�͸ı���Ͳ����
      ptDir = dir;
     
    /*�з�̹���Զ��ƶ�*/
    if(!good){
      Direction[] dirs = Direction.values();  //�����������Ϊ����
      if(step == 0){
        step = r.nextInt(12)+3;  //����ƶ�����
        int randomNumber = r.nextInt(dirs.length);  //����ƶ�����
        dir = dirs[randomNumber];
      }
      step--;
      if(r.nextInt(40)>30) this.fire();  //����Ƿ����ڵ�
    }
  }
  /*�з�̹�˸���*/
  public void fuhuo(){
    if(tc.tanks.size() < 20)
      while(true){
        int x = r.nextInt(700);
        int y = r.nextInt(500);
        Tank t = new Tank(x,y,false,Color.blue,Direction.D,tc);
        /*���̹����ǽ�غ����������λ��ֱ�����غ�Ϊֹ�Ž���̹�˼��뼯��*/
        if(t.getRect().intersects(tc.wall1.getRect())||t.getRect().intersects(tc.wall2.getRect())
            ||t.getRect().intersects(tc.wall3.getRect())
            ||t.getRect().intersects(tc.wall4.getRect())){
          continue;
        }
        else{
          tc.tanks.add(t);
          break;
        }
    }
  }
  /*�ӵ�����*/
  public void fire(){
    int x = this.x + Whith/2 - Missile.Whith/2;  //�����ӵ�����Ϊ̹���м�
    int y = this.y + Higth/2 - Missile.Higth/2;
    tc.missiles.add(new Missile(ptDir,color,x,y,good,tc)); //�����µ��ӵ�����뵽�ӵ�������
  }
  /*��ײ����ȡ̹�˵ķ�Χ*/
  public Rectangle getRect(){
    return new Rectangle(x,y,Whith,Higth);
  }
  /*��ִ��һ��λ��*/
  private void stay(){
    x = oldX;
    y = oldY;
  } 
  /*���ײǽ������stay������������һ��λ��*/
  public boolean hitWall(Wall w){ 
    if(this.live&&this.getRect().intersects(w.getRect())){
      this.stay();
      return true;
    }
    return false;
  }
  /*̹�˻���ײ���¼�*/
  public boolean hitTanks(List<Tank> tanks){ 
    for(int i=0;i<tanks.size();i++){
      Tank t=tanks.get(i);
      if(this!=t){//�Լ����Լ�������ײ
        /*�����ײ������һ��λ��*/
        if(this.live&&t.isLive()&&this.getRect().intersects(t.getRect())){
          this.stay();
          t.stay();
          return true;
        }
      }
    }
    return false;
  }
  /*��������ķ��亯��*/
  public Missile fire(Direction dir){
    if(!live) return null;
    int x=this.x+Whith/2-Missile.Whith/2;
    int y=this.y+Higth/2-Missile.Higth/2;
    Missile m=new Missile(dir,color,x, y,good, this.tc);
    tc.missiles.add(m);
    return m;
  }
  /*�����������*/
  private void superFire(){
    Direction[] dirs=Direction.values();
    for(int i=0;i<8;i++){
      fire(dirs[i]);//ѭ�����ð˸�����
    }
  }
  /*����Ѫ����*/
  private class BloodBar{
    /*��Ѫ��*/
    public void draw(Graphics g){
      Color c=g.getColor();
      g.setColor(Color.red);
      g.drawRect(x, y-10, Whith, 10);
      int w=Whith*Life/100;
      g.fillRect(x, y-10, w, 10);
      g.setColor(c);
    }
  }
  /*��Ѫ����*/
  public boolean eatBlood(Blood b){
    if(this.live&&b.isLive()&&this.isGood()&&this.getRect().intersects(b.getRect())){
      this.setLife(100);
      b.setLive(false);
      return true;
    }
    if(this.getRect().intersects(tc.wb.getRect()))
      this.Life = 100;
    return false;
  }
}