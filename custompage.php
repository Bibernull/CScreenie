<?php

	
    $allowedEnd   = "jpg";
    $path 		  = "uploads/images/";
    $name		  = $_FILES["file"]["name"];
    $splitData    = explode(".", $name);
    
    
    
    
	function generateRandName( $minNum, $maxNum, $stringSize ) {
		
		$newName = ""; 
		
		for( $startLetter = 0; $startLetter < $stringSize; $startLetter ++ ) 
		
			$newName .= rand( $minNum, $maxNum);
		
		
		return $newName;
	}

  
  if( sizeof($splitData) != 2 ) {
      echo "E_INVALIDTYPESIZE;".sizeof($splitData);
      die();
  }
      
  $fileEnd      = $splitData[1];
  $fileFront    = $splitData[0];
      
	if (  $fileEnd == $allowedEnd ) {
	
	  if ($_FILES["file"]["error"] > 0) 
	  
			echo "E_FAILED;".$_FILES["file"]["error"];
			
	    else {
		
			$name = generateRandName( 0, 99, 10 ).".".$allowedEnd;

			
			if (file_exists($name)) 
			
				 echo "E_DOUBLE;".$name; 

			 else {
				move_uploaded_file( $_FILES["file"]["tmp_name"], $path.$name );
				echo "index.php?file=".$name;
			}
			
		}
	}
	else   
		  echo "E_INVALIDTYPE;".$fileEnd;

?>