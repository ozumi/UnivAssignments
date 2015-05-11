x=raw_input()
L = list(range(10))
rs = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
checkx = x.replace(" ", "")
for a in L:
        for b in L:
                for c in L:
                        for d in L:
                                for e in L:
                                        rs[ord(x[0])-65] = e
                                        rs[ord(x[1])-65] = d
                                        rs[ord(x[2])-65] = c
                                        rs[ord(x[4])-65] = b
                                        rs[ord(x[5])-65] = a
                                        if e == 0:
                                                continue
                                        if b == 0:
                                                continue
                                        rs[ord(x[10])-65] =(c*a)%10
                                        rs[ord(x[9])-65] = (d*a)%10 + int((c*a)/10)
                                        rs[ord(x[8])-65] = (e*a)%10 + int((d*a)/10)
                                        rs[ord(x[7])-65] = int((e*a)/10)
                                        if rs[ord(x[7])-65] == 0:
                                                continue
                                        rs[ord(x[15])-65] =(c*b)%10
                                        rs[ord(x[14])-65] = (d*b)%10 + int((c*b)/10)
                                        rs[ord(x[13])-65] = (e*b)%10 + int((d*b)/10)
                                        rs[ord(x[12])-65] = int((e*b)/10)
                                        rs[ord(x[0])-65] = e
                                        rs[ord(x[1])-65] = d
                                        rs[ord(x[2])-65] = c
                                        rs[ord(x[4])-65] = b
                                        rs[ord(x[5])-65] = a
                                        if rs[ord(x[12])-65] == 0:
                                                continue
                                        rs[ord(x[20])-65] = (rs[ord(x[9])-65]+rs[ord(x[15])-65])%10
                                        rs[ord(x[19])-65] = (rs[ord(x[8])-65]+rs[ord(x[14])-65])%10 + int((rs[ord(x[9])-65]+rs[ord(x[15])-65])/10)
                                        rs[ord(x[18])-65] = (rs[ord(x[7])-65]+rs[ord(x[13])-65])%10 + int((rs[ord(x[8])-65]+rs[ord(x[14])-65])/10)
                                        rs[ord(x[17])-65] = (rs[ord(x[12])-65]) + int((rs[ord(x[7])-65]+rs[ord(x[13])-65])/10)
                                        rs[ord(x[0])-65] = e
                                        rs[ord(x[1])-65] = d
                                        rs[ord(x[2])-65] = c
                                        rs[ord(x[4])-65] = b
                                        rs[ord(x[5])-65] = a
                                        if rs[ord(x[17])-65] == 0:
                                                continue
                                        if len(set(checkx)) != len(set(rs)):
                                                continue
                                        else:
                                                if (100*rs[ord(x[0])-65]+10*rs[ord(x[1])-65]+rs[ord(x[2])-65])*rs[ord(x[5])-65] == rs[ord(x[7])-65]*1000 + rs[ord(x[8])-65]*100 + rs[ord(x[9])-65]*10 + rs[ord(x[10])-65]:
                                                        if (100*rs[ord(x[0])-65]+10*rs[ord(x[1])-65]+rs[ord(x[2])-65])*rs[ord(x[4])-65] == rs[ord(x[12])-65]*1000 + rs[ord(x[13])-65]*100 + rs[ord(x[14])-65]*10 + rs[ord(x[15])-65]:
                                                                if (100*rs[ord(x[0])-65]+10*rs[ord(x[1])-65]+rs[ord(x[2])-65])*(10*rs[ord(x[4])-65] + rs[ord(x[5])-65]) ==  10000*rs[ord(x[17])-65] + 1000*rs[ord(x[18])-65] + 100*rs[ord(x[19])-65] + 10*rs[ord(x[20])-65] + rs[ord(x[21])-65]:
                                                                        if rs[ord(x[5])-65] == a and rs[ord(x[4])-65] == b and rs[ord(x[2])-65] == c and rs[ord(x[1])-65] == d and rs[ord(x[0])-65] == e:
                                                                                result1 = 100*rs[ord(x[0])-65]+10*rs[ord(x[1])-65]+rs[ord(x[2])-65]
                                                                                result2 = 10*rs[ord(x[4])-65]+rs[ord(x[5])-65]
                                                                                print('%d %d' % (result1,result2))


