import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;
import java.util.List;
 
import javax.swing.JFrame;
 
public class TankClient extends JFrame{
  /**
   * @param args
   */
  Image OffScrennImage = null;  //˫�����ڴ�ͼƬ�洢
  /*��Ϸ��С*/
  public static final int GAME_WIDTH = 800;  //�����
  public static final int GAME_HEIGTH = 600;  //�����
   
  Tank myTank = new Tank(500,400,true,Color.red,Tank.Direction.STOP, this);//�ҷ�̹����
  List<Missile> missiles = new ArrayList<Missile>();//�ӵ��ļ���
  List<Explode> explode = new ArrayList<Explode>();//��ը����
  List<Tank> tanks = new ArrayList<Tank>();  //̹�˼���
  Wall wall1 = new Wall(150,200,20,300,this);  //ǽ1
  Wall wall2 = new Wall(250,500,300,20,this);  //ǽ2
  Wall wall3 = new Wall(650,200,20,300,this);  //ǽ2
  Wall wall4 = new Wall(250,300,300,20,this);  //ǽ2
  Wall wb = new Wall(750,550,40,40,this);  //ǽ2
  Blood b = new Blood();  //Ѫ��
   
   
  public static void main(String[] args) {
    // TODO Auto-generated method stub
    TankClient tc=new TankClient();
    tc.lauchFrame();
  }
 
  private void lauchFrame() {
    // TODO Auto-generated method stub
    for (int i = 0; i < 10; i++){
      tanks.add(new Tank(50+40*(i+1), 50, false,Color.blue,Tank.Direction.D, this));
    }
    this.setLocation(100, 100);  //���ڳ�ʼ�����
    this.setSize(GAME_WIDTH, GAME_HEIGTH);    //���ڳ�ʼ��С
    this.setTitle("TankWar");  //��������
    /*���ڼ���*/
    this.addWindowListener(new WindowAdapter() {
      @Override
      /*���˳���֮������*/
      public void windowClosing(WindowEvent e) {
        // TODO Auto-generated method stub
        System.exit(0);  //�˳�
      }
    });
    this.addKeyListener(new KeyMoniton());  //���ü��̼���
    this.setVisible(true);  //���ô�������
    this.setResizable(false);  //���ô��ڲ��ɸı��С
    this.getContentPane().setBackground(Color.green);  //���ô���ǰ��ɫΪ��ɫ
    new Thread(new PaintThread()).start();  //��ʼ����PaintThread��run
  }
 
  @Override
  public void paint(Graphics g) {
    // TODO Auto-generated method stub
    //GraphicsΪ������
    super.paint(g);
    myTank.draw(g);
    wall1.draw(g);
    wall2.draw(g);
    wall3.draw(g);
    wall4.draw(g);
    wb.draw(g);
    b.draw(g);
    myTank.eatBlood(b);
    myTank.hitWall(wall1);
    myTank.hitWall(wall2);
    myTank.hitWall(wall3);
    myTank.hitWall(wall4);
    /*ѭ���ӵ�����*/
    for (int i = 0; i < missiles.size(); i++){
      Missile m = missiles.get(i);  //��ȡ��ǰ�ӵ�
      m.hitTanks(tanks);  //�Լ��ӵ������з�̹��
      m.hitWall(wall1);  //�ӵ���ǽ
      m.hitWall(wall2);
      m.hitWall(wall3);
      m.hitWall(wall4);
      m.hitTank(myTank);//�����ӵ�����Լ���̹��
      m.draw(g);  //���ӵ�
    }
    for  (int i = 0; i < explode.size(); i++){
      explode.get(i).draw(g);  //����ը
    }
    for (int i = 0; i < tanks.size(); i++){
      Tank t = tanks.get(i);
      t.draw(g);  //���з�̹��
      t.hitTanks(tanks);
      t.hitWall(wall1);  //̹����ǽ
      t.hitWall(wall2);
      t.hitWall(wall3);
      t.hitWall(wall4);
    }
    //g.setFont(new Font("����",Font.BOLD,20));
    g.drawString("missiles count:"+missiles.size(), 10, 50);//��ʾ
    g.drawString("explode count:"+explode.size(), 10, 80);//��ʾ
    g.drawString("tanks count:"+tanks.size(),10, 110);
    g.drawString("myTank Life:"+myTank.getLife(), 10, 130);
    g.drawString("��Ѫ:", 750, 540);
    g.drawString("������ƶ�����E:�ͷ��ƶ�Ѫ��", 10, 590);
    g.drawString("z�����䶫��-31��a�����䶫��-41;", 10, 570);
    g.drawString("F2�����F3���з�����Զ�20��", 10, 550);
    g.drawString("R��λ�û�ԭ;Q:Ѫ������", 10, 530);
  }
   
  @Override
  /*repaint-��update->paint*/
  public void update(Graphics g) {
    // TODO Auto-generated method stub
    super.update(g);
    if(OffScrennImage == null)
      OffScrennImage = this.createImage(GAME_WIDTH, GAME_HEIGTH);
    Graphics goffscrenn = OffScrennImage.getGraphics();  //����һ���ڴ滭����ɫΪǰ��ͼƬ��ɫ
    Color c = goffscrenn.getColor();  //�����ȱ���ǰ����ɫ
    goffscrenn.setColor(Color.green);  //�����ڴ滭����ɫΪ��ɫ
    goffscrenn.fillRect(0, 0, GAME_WIDTH, GAME_HEIGTH);  //����ͼƬ����СΪ��Ϸ��С
    goffscrenn.setColor(c);  //��ԭ��ɫ
    g.drawImage(OffScrennImage, 0, 0, null);  //�ڽ��滭�������ͼƬ
    paint(goffscrenn);  //���ڴ滭�ʵ��ø�paint
  }
 
  private class PaintThread implements Runnable{
 
    @Override
    public void run() {
      // TODO Auto-generated method stub
      while(true){
        repaint();  //����˳��repaint->update->paint
        try{
          Thread.sleep(50);  //ÿ��50����ˢ�»���һ��
        }catch(Exception e){
          e.printStackTrace();
        }
      }
    }
     
  }
  /*������Ӧ*/
  private class KeyMoniton extends KeyAdapter{
 
    /*���¼�����Ӧ*/
    @Override
    public void keyPressed(KeyEvent e) {
      // TODO Auto-generated method stub
      super.keyPressed(e);
      myTank.KeyPressed(e);
    }
    /*̧�������Ӧ*/
    @Override
    public void keyReleased(KeyEvent e) {
      // TODO Auto-generated method stub
      super.keyReleased(e);
      myTank.keyReleased(e);
    }
     
  }
}