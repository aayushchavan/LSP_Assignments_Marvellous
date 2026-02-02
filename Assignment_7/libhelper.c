int sumoffactors(int no)
{
    int ans=0;
    for (int i=1;i<=no/2;i++)
    {
        if(no%i==0)
        {
            ans=ans+i;
        }

    }
    return ans;

}