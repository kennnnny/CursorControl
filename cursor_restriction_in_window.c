#include <stdio.h>
#include <windows.h>

int main(void)
{
    RECT rect;
 
    //左上角
    rect.top = 100;   //上
    rect.left = 100;  //左
 
    //右下角
    rect.bottom = rect.top + 255;  //底
    rect.right = rect.left + 255;  //右
 
    ClipCursor(&rect);
    Sleep(5000);
    ClipCursor(NULL);  //释放
    return 0;
}
 
/*
函数原型
    BOOL ClipCursor(CONST RECT *lpRect);
参数
    IpRect：指向RECT结构的指针，该结构包含限制矩形区域左上角和右下角的屏幕坐标
    如果该指针为NULL（空），则鼠标可以在屏幕的任何区域移动
*/
 
/*
函数原型
    //检取一个矩形区域的屏幕坐标，光标被限制在该矩形区域之内
    BOOL GetClipCursor(LPRECT IpRect);
参数
    IpRect：一个RECT结构的指针；接收限制矩形的屏幕坐标。
    如果该光标没有被限制在一个矩形区域内，则该RECT结构接收屏幕的尺寸
返回值
    如果成功，返回非零；如果失败，返回值为零
    若想获得更多错误信息，请调用GetLastError函数
*/