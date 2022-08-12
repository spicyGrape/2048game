#ifndef _Merge_
#define _Merge_


int mergeup(int (*arr)[4]);
int mergedown(int (*arr)[4]);
int mergeleft(int (*arr)[4]);
int mergeright(int (*arr)[4]);

//用于合并每行或每列的函数,第一个参数传入数组,第二个参数传入方向 1:向上 2:向下 3:向左 4:向右
int merge(int (*arr)[4], int direction)
{
    switch(direction)
    {
        case 1:
        return mergeup(arr);
        case 2:
        return mergedown(arr);
        case 3:
        return mergeleft(arr);
        case 4:
        return mergeright(arr);
    }
}

int mergeup(int (*arr)[4])
{
    int count = 0; //计数移动次数,便于操作是否有效
    //归并部分
    for(int j = 0; j < 4; j++)
    {
        int target = -1, ti = 0;
        for(int i = 0; i < 4; i++)
        {
            if(arr[i][j] != 0)
            {
                if(arr[i][j] == target)
                {
                    arr[ti][j] = 2 * arr[ti][j];
                    arr[i][j] = 0;
                    target = -1;
                    ti = 0;
                    count ++;
                    i = -1;
                }
                else
                {
                    target = arr[i][j];
                    ti = i;
                }
            }
        }
    }

    //移动部分

    //分三个位置,从特定位置开始,向下数到第一个非0,统计移动次数,进行一次移动,若到最底仍是0 则不移动,且取消后面的移动
    for(int j = 0; j < 4; j++)
    {
        int check = 0;      //用于控制每一位移动操作是否有意义
        for(int i = 1; i < 4; i++)          //检查第一位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[0][j] == 0) count ++;
        while(arr[0][j] == 0)               //进行移动
        {
            arr[0][j] = arr[1][j];
            arr[1][j] = arr[2][j];
            arr[2][j] = arr[3][j];
            arr[3][j] = 0;
        }
        check = 0;
        for(int i = 2; i < 4; i++)          //检查第二位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[1][j] == 0) count ++;
        while(arr[1][j] == 0)               //进行移动
        {
            arr[1][j] = arr[2][j];
            arr[2][j] = arr[3][j];
            arr[3][j] = 0;
        }
        check = 0;
        if(arr[3][j] != 0) check = 1;       //检查第三位移动是否有意义
        if(check == 0) continue;
        if(arr[2][j] == 0) count ++;
        while(arr[2][j] == 0)               //进行移动
        {
            arr[2][j] = arr[3][j];
            arr[3][j] = 0;
        }
    }
    return count;
}

int mergedown(int (*arr)[4])
{
    int count = 0; //计数移动次数,便于操作是否有效
    //归并部分
    for(int j = 0; j < 4; j++)
    {
        int target = -1, ti = 3;
        for(int i = 3; i >= 0; i--)
        {
            if(arr[i][j] != 0)
            {
                if(arr[i][j] == target)
                {
                    arr[ti][j] = 2 * arr[ti][j];
                    arr[i][j] = 0;
                    target = -1;
                    ti = 3;
                    count ++;
                    i = 4;
                }
                else
                {
                    target = arr[i][j];
                    ti = i;
                }
            }
        }
    }

    //移动部分

    //分三个位置,从特定位置开始,向下数到第一个非0,统计移动次数,进行一次移动,若到最底仍是0 则不移动,且取消后面的移动
    for(int j = 0; j < 4; j++)
    {
        int check = 0;      //用于控制每一位移动操作是否有意义
        for(int i = 2; i >= 0; i--)          //检查第一位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[3][j] == 0) count ++;
        while(arr[3][j] == 0)               //进行移动
        {
            arr[3][j] = arr[2][j];
            arr[2][j] = arr[1][j];
            arr[1][j] = arr[0][j];
            arr[0][j] = 0;
        }
        check = 0;
        for(int i = 1; i >= 0; i--)          //检查第二位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[2][j] == 0) count ++;
        while(arr[2][j] == 0)               //进行移动
        {
            arr[2][j] = arr[1][j];
            arr[1][j] = arr[0][j];
            arr[0][j] = 0;
        }
        check = 0;
        if(arr[0][j] != 0) check = 1;       //检查第三位移动是否有意义
        if(check == 0) continue;
        if(arr[1][j] == 0) count ++;
        while(arr[1][j] == 0)               //进行移动
        {
            arr[1][j] = arr[0][j];
            arr[0][j] = 0;
        }
    }
    return count;
}

int mergeleft(int (*arr)[4])
{
    int count = 0; //计数移动次数,便于操作是否有效
    //归并部分
    for(int i = 0; i < 4; i++)
    {
        int target = -1, tj = 0;
        for(int j = 0; j < 4; j++)
        {
            if(arr[i][j] != 0)
            {
                if(arr[i][j] == target)
                {
                    arr[i][tj] = 2 * arr[i][tj];
                    arr[i][j] = 0;
                    target = -1;
                    tj = 0;
                    count ++;
                    j = -1;
                }
                else
                {
                    target = arr[i][j];
                    tj = j;
                }
            }
        }
    }

    //移动部分

    //分三个位置,从特定位置开始,向下数到第一个非0,统计移动次数,进行一次移动,若到最底仍是0 则不移动,且取消后面的移动
    for(int i = 0; i < 4; i++)
    {
        int check = 0;      //用于控制每一位移动操作是否有意义
        for(int j = 1; j < 4; j++)          //检查第一位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[i][0] == 0) count ++;
        while(arr[i][0] == 0)               //进行移动
        {
            arr[i][0] = arr[i][1];
            arr[i][1] = arr[i][2];
            arr[i][2] = arr[i][3];
            arr[i][3] = 0;
        }
        check = 0;
        for(int j = 2; j < 4; j++)          //检查第二位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[i][1] == 0) count ++;
        while(arr[i][1] == 0)               //进行移动
        {
            arr[i][1] = arr[i][2];
            arr[i][2] = arr[i][3];
            arr[i][3] = 0;
        }
        check = 0;
        if(arr[i][3] != 0) check = 1;       //检查第三位移动是否有意义
        if(check == 0) continue;
        if(arr[i][2] == 0) count ++;
        while(arr[i][2] == 0)               //进行移动
        {
            arr[i][2] = arr[i][2];
            arr[i][3] = 0;
        }
    }
    return count;
}

int mergeright(int (*arr)[4])
{
    int count = 0; //计数移动次数,便于操作是否有效
    //归并部分
    for(int i = 0; i < 4; i++)
    {
        int target = -1, tj = 0;
        for(int j = 3; j >= 0; j--)
        {
            if(arr[i][j] != 0)
            {
                if(arr[i][j] == target)
                {
                    arr[i][tj] = 2 * arr[i][tj];
                    arr[i][j] = 0;
                    target = -1;
                    tj = 3;
                    count ++;
                    j = 4;
                }
                else
                {
                    target = arr[i][j];
                    tj = j;
                }
            }
        }
    }

    //移动部分

    //分三个位置,从特定位置开始,向下数到第一个非0,统计移动次数,进行一次移动,若到最底仍是0 则不移动,且取消后面的移动
    for(int i = 0; i < 4; i++)
    {
        int check = 0;      //用于控制每一位移动操作是否有意义
        for(int j = 3; j >= 0; j--)          //检查第一位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[i][3] == 0) count ++;
        while(arr[i][3] == 0)               //进行移动
        {
            arr[i][3] = arr[i][2];
            arr[i][2] = arr[i][1];
            arr[i][1] = arr[i][0];
            arr[i][0] = 0;
        }
        check = 0;
        for(int j = 2; j >= 0; j--)          //检查第二位移动是否有意义
        {
            if(arr[i][j] != 0) check = 1;
        }
        if(check == 0) continue;
        if(arr[i][2] == 0) count ++;
        while(arr[i][2] == 0)               //进行移动
        {
            arr[i][2] = arr[i][1];
            arr[i][1] = arr[i][0];
            arr[i][0] = 0;
        }
        check = 0;
        if(arr[i][0] != 0) check = 1;       //检查第三位移动是否有意义
        if(check == 0) continue;
        if(arr[i][1] == 0) count ++;
        while(arr[i][1] == 0)               //进行移动
        {
            arr[i][1] = arr[i][0];
            arr[i][0] = 0;
        }
    }
    return count;
}


#endif