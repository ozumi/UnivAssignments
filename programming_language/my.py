
num = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
result = list()
const = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
lstnum = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]
over = 0
key = raw_input()

for i in lstnum:
	for j in num:
		if key[i]==arr[j]:
			const[i] = j
		elif key[i]==" ":
			continue

for i in num:
	for j in num:
		for k in num:
			for l in num:
				for m in num:
					go = False
					arr[const[0]]=i
					arr[const[1]]=j
					arr[const[2]]=k
                                	arr[const[4]]=l
                                        arr[const[5]]=m

					if k*m < 10:
						arr[const[10]]=k*m
						over = 0
					else:
						arr[const[10]]=(k*m)%10
						over = int((k*m-arr[const[10]])/10)
					
					if j*m+over < 10:
						arr[const[9]]=j*m+over
						over = 0
					else:	
						arr[const[9]] = (j*m+over)%10
						over = int((j*m+over-arr[const[9]])/10)	          

					if i*m+over < 10:
						arr[const[8]]=i*m+over
						over = 0
					else:
						arr[const[8]]=(i*m+over)%10
						over = int((i*m+over-arr[const[8]])/10)
					
					arr[const[7]]=over
					over = 0

                                       
					if k*l < 10:
						arr[const[15]]=k*l
						over = 0
					else:
						arr[const[15]]=(k*l)%10
						over = int((k*l-arr[const[15]])/10)

					if j*l+over < 10:
						arr[const[14]]=j*l+over
						over = 0
					else:
						arr[const[14]]=(j*l+over)%10
						over = int((j*l+over-arr[const[14]])/10)

					if i*l+over < 10:
						arr[const[13]]=i*l+over
						over = 0
					else:
						arr[const[13]]=(i*l+over)%10
						over = int((i*l+over-arr[const[13]])/10)
						
			
					arr[const[12]]=over
					over = 0

                                      
					arr[const[21]]=arr[const[10]]

					if arr[const[9]]+arr[const[15]] < 10:
						arr[const[20]]=arr[const[9]]+arr[const[15]]
						over = 0
					else:
						arr[const[20]]=(arr[const[9]]+arr[const[15]])%10
						over = int((arr[const[9]]+arr[const[15]]-arr[const[20]])/10)

					if arr[const[8]]+arr[const[14]]+over < 10:
						arr[const[19]]=arr[const[8]]+arr[const[14]]+over
						over = 0
					else:		
						arr[const[19]]=(arr[const[8]]+arr[const[14]]+over)%10
						over = int((arr[const[8]]+arr[const[14]]+over-arr[const[19]])/10)

					if arr[const[7]]+arr[const[13]]+over < 10:
						arr[const[18]]=arr[const[7]]+arr[const[13]]+over
						over = 0
					else:
						arr[const[18]]=(arr[const[7]]+arr[const[13]]+over)%10
						over = int((arr[const[7]]+arr[const[13]]+over-arr[const[18]])/10)

					if over == 0:
						arr[const[17]]=arr[const[12]]
						over = 0
					else:
						arr[const[17]]=arr[const[12]]+over
						over = 0
					   
					for a in num:
						for b in num:
							if a != b:
								if arr[a] == arr[b] :
									go = True
				
                                                             
					if go==False:
						                                                  		
						if (arr[const[0]]*100 + arr[const[1]]*10 + arr[const[2]])*arr[const[5]] == (arr[const[7]]*1000+arr[const[8]]*100+arr[const[9]]*10+arr[const[10]]):
									
							if (arr[const[0]]*100 + arr[const[1]]*10 + arr[const[2]])*arr[const[4]] == (arr[const[12]]*1000+arr[const[13]]*100+arr[const[14]]*10+arr[const[15]]):
							
								if (arr[const[7]]*1000+arr[const[8]]*100+arr[const[9]]*10+arr[const[10]])+(arr[const[12]]*10000+arr[const[13]]*1000+arr[const[14]]*100+arr[const[15]]*10)==(arr[const[17]]*10000+arr[const[18]]*1000+arr[const[19]]*100+arr[const[20]]*10+arr[const[21]]):
								
									first = str(arr[const[0]]*100 + arr[const[1]]*10 + arr[const[2]])
									second = str(arr[const[4]]*10 + arr[const[5]])
									answer = first + " " + second 
									index = 0
									
									if len(result)==0:
										result.append(answer)
									else:
										while index<len(result) :
											if(result[index]==answer):
												break
											else:
												if index+1==len(result):
													result.append(answer)
												
												else:
													index+=1
													continue
									
								
				
order = 0
while order<len(result):
	print(result[order])
	order+=1
