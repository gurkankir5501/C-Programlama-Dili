# include  < stdio.h >
# include  < stdlib.h >

yapı düğümü {
	int veri;
	struct düğümü * sonraki;
};

int  main () {
	
	struct düğümü * ilkdugum = NULL ;
	ilkdugum = ( struct node *) malloc ( sizeof ( struct node));
	yapı düğümü * ikincidugum = ( yapı düğümü *) malloc ( sizeof ( yapı düğümü));
	
	ilkdugum-> veri = 150 ;
	ilkdugum-> sonraki = ikincidugum;
	
	ikincidugum -> veri = 200 ;
	ikincidugum -> sonraki = NULL ;
	
	printf ( " % d -> % d " , ilkdugum-> veri , ikincidugum-> veri );
}
