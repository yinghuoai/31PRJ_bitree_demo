void qiuqiu(void)
{
    if (init_graph() == FAILURE)
    {
        printf("Initialize graph mode failure\n");
        exit(EXIT_FAILURE);
    }
 
    bsktball_ani();

	closegraph(); 	
    
}