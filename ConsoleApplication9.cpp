// ConsoleApplication9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <time.h>
#include <map>
#include "windows.h"
//#include <sys/time.h>
#include "string.h"
#include "test.h"
//
//std::string fa_getSysTime()
//{
//    char chTime[30];
//    struct tm *date;
//    time_t long_time;
//    time( &long_time );                
//    date = localtime( &long_time );
//    sprintf(chTime,"%02d:%02d:%02d %04d\0",
//        date->tm_hour,date->tm_min,date->tm_sec,date->);
//    return (std::string)chTime;
//}

class MyTimer{
 
private:
    LARGE_INTEGER large_integer;
    __int64 IntStart;
    __int64 IntEnd;
    double DobDff;
    double DobMillseconds;
 
public:
    MyTimer(){};
 
    void TimerStart(){
        QueryPerformanceFrequency(&large_integer);
        DobDff = large_integer.QuadPart;
 
        QueryPerformanceCounter(&large_integer);
        IntStart = large_integer.QuadPart;
    }
 
    double TimerFinish(){
        QueryPerformanceCounter(&large_integer);
        IntEnd = large_integer.QuadPart;
        DobMillseconds = (IntEnd - IntStart) * 1000 / DobDff; //转为ms
        return DobMillseconds;
    }
};

void transfer(unsigned char * srcdata, unsigned char * desdata, int length)
{
    int iIndex = 0;
    memset(desdata, 0, sizeof(desdata));
    for (; iIndex < length; ++iIndex)
    {
        *(desdata + iIndex) = *(srcdata + length - iIndex - 1);
    }
}
extern int testadd(int i, int j);

int _tmain(int argc, TCHAR* argv[])
{
    unsigned short srcdata = 5376;
    unsigned short desdata = 0;
    transfer((unsigned char*)&srcdata, (unsigned char*)&desdata, sizeof(desdata));
    TCHAR* a1 = argv[0];
    TCHAR* a2 = argv[1];
    TCHAR* a3 = argv[2];

    MyTimer timernew;
    //Dummyfunc();
    int ii = char(0);
    char s = 0;
    //std::cin >> s;
    //std::cout<<s;
    int isize = 9000000;
    clock_t start,ends;

    std::map<int, int> m_map;
    for (int i = 0; i < isize; ++i)
    {
        m_map[i] = i;
    }
    start=::GetTickCount();
    //timernew.TimerStart();
    int ivalue = 0;

    for (int i = 0; i < m_map.size(); ++i)
    {
        ivalue = m_map[i];
    }
    ends=::GetTickCount();
    printf("map  %d\n", ends - start);
    //printf("map  %d\n", timernew.TimerFinish());
    
    
    std::vector<int> m_vector;
    for (int i = 0; i < isize; ++i)
    {
        m_vector.push_back(i);
    }
    start=::GetTickCount();
    //timernew.TimerStart();
    ivalue = 0;

    for (int i = 0; i < m_vector.size(); ++i)
    {
        ivalue += m_vector[i];
    }
    ends=::GetTickCount();
    printf("vector []  %d\n", ends - start);
    //printf("vector []  %d\n", timernew.TimerFinish());
    
    start=::GetTickCount();
    //timernew.TimerStart();
    ivalue = 0;

    for (int i = 0; i < m_vector.size(); ++i)
    {
        ivalue += m_vector.at(i);
    }
    ends=::GetTickCount();
    printf("vector at  %d\n", ends - start);
    //printf("vector at  %d\n", timernew.TimerFinish());

    
    start=::GetTickCount();
    //timernew.TimerStart();
    ivalue = 0;

    for (std::vector<int>::iterator iter = m_vector.begin(); iter != m_vector.end(); ++iter)
    {
        ivalue += *iter;
    }
    ends=::GetTickCount();
    printf("vector iterator ++iter  %d\n", ends - start);
    //printf("vector iterator  %d\n", timernew.TimerFinish());

    std::list<int> m_list;
    for (int i = 0; i < isize; i++)
    {
        m_list.push_back(i);
    }
    
    start=::GetTickCount();
    //timernew.TimerStart();
    for (std::list<int>::iterator iter = m_list.begin(); iter != m_list.end(); ++iter)
    {
        ivalue = *iter;
    }
    ends=::GetTickCount();
    printf("list ++iter  %d\n", ends - start);
    //printf("list  %d\n", timernew.TimerFinish());
    testadd(1, 3);
    //m_list
	return 0;
}

