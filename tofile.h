int tofile(double* data,int repeat, FILE *randfile){
int i;

//int fo;
randfile = fopen("randomnums.txt", "w");
//fo = fwrite(data, sizeof(data),1,randfile);
for(i=0; i<repeat; i++){
fprintf(randfile,"%f\n", data[i]);
}
fclose(randfile);
};