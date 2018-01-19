double sysseed(){
	time_t now;
	now  =time(NULL);
	return((int) now%100000);
}