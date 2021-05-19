#ifndef CONFIG_H
#define CONFIG_H
/**********  游戏配置数据  **********/
#define GAME_WIDTH  468                         //宽度
#define GAME_HEIGHT 770                         //高度，不能超过852
#define GAME_TITLE "飞机大战 v2.0"               //标题
//#define GAME_RES_PATH "./res.qrc"
#define GAME_ICON ":/res/app.ico"               //图标
#define MAP_PATH ":/res/background.jpg"         //背景图片
#define MAP_SCROLL_SPEED 2;                     //游戏时背景动画的速度（超过20，体验开始下降）
#define GAME_RATE 10                            //游戏速度（越大越慢）
#define MY_PATH ":/res/myplane.png"             //我的飞机图片
#define BULLET_PATH ":/res/bullet.png"          //子弹的图片
#define BULLET_SPEED 6                          //子弹飞行速度
#define BULLET_NUM 100                          //屏幕内玩家子弹数量上限
#define Bullet_INTERVAL 15                      //玩家和敌机的子弹间隔
#define ENEMY_PATH ":/res/otherplane.png"       //敌机图片
#define ENEMY_SPEED 3                           //敌机速度，不要超过子弹的速度
#define ENEMY_NUM 30                            //敌机数
#define ENEMY_INTERVAL 40                       //敌机来的间隔
#define START_BUTTON_PATH ":/res/Startbutton.png"  //开始按钮的图片
#define RESTART_BUTTON_PATH ":/res/restart.png"    //重新开始按钮的图片
#define FRAME_PATH ":/res/frame.jpg"               //游戏结束时显示的图片
#define CONTINUE_PATH ":/res/continuebtn.png"      //继续游戏按钮图片
#endif // CONFIG_H
