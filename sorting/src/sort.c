int cmpfunc_asc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int cmpfunc_desc (const void * a, const void * b){
	return ( *(int*)b - *(int*)a );
}
