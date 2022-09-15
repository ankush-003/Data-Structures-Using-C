void fast_transpose(sparse a[],sparse b[])
{
    int row_terms[20],start_pos[20];
    int i,j;
    for(i=0;i<20;i++)
    {
        row_terms[i] = 0;
        start_pos[i] = 0;
    }
    for(j = 1;j<=a[0].val;j++)
    {
        row_terms[a[i].col]++;
    }
    st_pos[0] = 1;
    for(i=1;a[0].col;i++)
    {
        st_pos[i] = st_pos[i-1] + row_terms[i-1];
    }
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].value;

    for(i = 1;i<a[0].value;i++)
    {
        
    }
}