public int[] binaryInsertSort(int[] array){
	for(int i = 0;i<array.length;i++){
		int temp = array[i];//�����뵽ǰ���������е�ֵ		
		int left = 0;//�������е����		
		int right = i-1;//�������е��Ҳ�		
		int middle = 0;//�������е��м�		
		while(left <= right){			
			middle = (left + right)/2;//��ֵ			
			if(temp<array[middle]){				
			right = middle-1;			
		}else{				
			left = middle + 1;			
		}		
	}		
		for(int j = i-1;j>=left;j--){			
		//��i-1��left��������ƶ�һλ,�ȴ�tempֵ����			
			array[j+1] = array[j];		
		}		
		if(left != i ){			
			array[left] = temp;		
		}	
	}
	return array;
}
