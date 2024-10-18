#include <stdint.h>
#include <stdio.h>
#include "params.h"
#include "reduce.h"

int main(void)
{
    printf("Input a interger: ");
    int32_t input;
    scanf("%d",&input);
    int16_t m_out=montgomery_reduce(input);
    printf("mont_out= %d | 0x%x\n",m_out,m_out);
    if ((input>=-32767) && (input<=32768))
    {
        int16_t b_out=barrett_reduce(input);
        printf("barret_out= %d | 0x%x\n",b_out,b_out);
    }
    return 0;
}
