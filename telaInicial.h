
#define MAX_LEN 300
 
void print_image(FILE *fptr);
 
void inicializa()
{
    char *filename = "foto.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
    }
 
    print_image(fptr);
 
    fclose(fptr);
    printf("\n\n\n\n\n\n\n");
}
 
void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}
