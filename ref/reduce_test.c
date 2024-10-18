#include <stdint.h>
#include <stdio.h>
#include "params.h"
#include "reduce.h"

int main(void)
{
    printf("input,input_hex,barrett_int,barrett_hex,mont_int,mont_hex\n");
    for (int32_t i=-2147483648; i<=2147483647;i++)
    {
    
        int16_t m_out=montgomery_reduce(i);
        if ((i>=-32767) && (i<=32768))
        {
            int16_t b_out=barrett_reduce(i);
            printf("%d,0x%x,%d,0x%x,%d,0x%x\n",i,i,b_out,b_out,m_out,m_out);
        }
        else
        {
            printf("%d,0x%x,N/A,N/A,%d,0x%x\n",i,i,m_out,m_out);
        }
    }
    return 0;
}
