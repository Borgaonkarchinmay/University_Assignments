import re
def matchre(data,*args):
    for regstr in args:
        matchObj = re.search( regstr+'.*', data)
        if matchObj:
            print(matchObj.group(0).lstrip().rstrip())
        else:
            print("No ",regstr,"found")
        

fo = open("input.txt", "r") #fo=filehandle
data=fo.read()
matchre(data,"MIME-Version:","Date:","Subject:","From:","To:","Sender:")
fo.close()