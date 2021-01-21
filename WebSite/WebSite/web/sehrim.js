
 var slayt=document.getElementsByClassName("slayt");
 var resimsayisi=slayt.length;
 var resimnu=0;
 
 resimgoster(resimnu);
 
  function onceki(){
	  resimnu--;
	  resimgoster(resimnu);
  }
  
  function sonraki(){
	  resimnu++;
	  resimgoster(resimnu);
  }
  
 
  
  
  function resimgoster(resimnumarasi){
	  
	  resimnu=resimnumarasi;
	  
	  if(resimnumarasi>=resimsayisi){
		  resimnu=0;
	  }
      if(resimnumarasi<0){
		  resimnu=resimsayisi-1;
	  }
      for(i=0;i<resimsayisi;i++){
		  slayt[i].style.display="none";
	  }

     slayt[resimnu].style.display="block";

 }