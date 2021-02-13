// Chef is a programmer. In his computer, he is running a caching service, Memcached.

// He can give the commands "start", "restart" or "stop" to the service, the functionalities of which are specified below.

//     "start": Start the service.
//     "restart": If the service is started, do nothing. Otherwise, start the service.
//     "stop": If the service is not running, give an error. Otherwise, stop the service.

// The service is initially not running. You are given n
// commands that he then gives to the program in sequence.
// Your task is to identify whether some error/s were encountered while running these commands.

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t > 0)
    {
        int n;
        cin>>n;
        while(n > 0)
        {
            string s;
            cin >> s;

            int status = 0;
            bool flag = true;
            if(s == "start")
            {
                if(status == 0)
                {
                    status = 1;
                }
            }
            else if(s == "restart")
            {
                // Only if it is not started.
                if(status == 0)
                {
                    status = 1;
                }
            }
            else if(s == "stop")
            {
                if(status == 0)
                {
                    flag = true;
                }
                else
                {
                    status = 0;
                }
            }
            n -= 1;
        }
        t -= 1;
    }
    return 0;
}

