
// Controller class for GUI visualForce page

public class bmi {
	public Double weight {get; set;}
	public Double height {get; set;}
	public Double bmi {get; set;}
	public String category {get; set;}
	
	public bmi(){
		weight = 0;
		height = 0;
		bmi = 0;
		category = 'NA';
	}

	public void computeBMI(){
		bmi = weight/(height*height);
		
		if(bmi < 18.5){
			category = 'underweight';
		}else if(bmi < 25){
			category = 'normal';
		}else if(bmi < 30){
			category = 'overweight';
		}else{
			category = 'obess';
		}
	}
}

// VisualForce page for UI

/*

<apex:page controller="bmi" standardStylesheets="false">
    <style>
    	.bmi{
        	width:240px;
        	border-style : solid;
        	border-radius : 5px;
        	padding : 8px;
        	margin : auto;
        }
        .title{
        	text-align:center;
        }
        .inp-label{
        	display : inline-block;
        }
    </style>
    
    <div class='bmi'>
        <h2 class='title'>
            BMI
        </h2>
        <hr/>
		<apex:form>
            <label class="inp-label" for="weight">Weight(in Kg): </label>
            <apex:inputText id="weight" value="{!weight}"/> <br/>
            
            <label class="inp-label" for="height">Height(in meter): </label>
            <apex:inputText id="height" value="{!height}"/> <br/>
                
			<apex:commandButton value="compute BMI" action="{!computeBMI}"/><br/>
            <hr/>
            
            <label class="inp-label" for="bmi">BMI: </label>
            <apex:outputText id="bmi" value="{!bmi}"/> <br/>
            
            <label class="inp-label" for="category">Category: </label>
            <apex:outputText id="categotry" value="{!category}"/> <br/>
        </apex:form>
    </div>
</apex:page>


// Brief Revision
// Data types
String name = 'chinmay';
Decimal n1 = 2353.1351235;
Integer n2 = 2;
Long n3 = 36646223523L;
Object obj = name;
System.debug('num: ' + n1);
System.debug('num: ' + n2);
System.debug('num: ' + n3);
System.debug('object: ' + obj);
System.debug('blob: ' + Blob.valueOf(name));

// Collection

List<Integer> arr = new List<Integer>();

Integer arrSize = 10;
for(Integer i = 1; i <= arrSize; i++){
    arr.add(i);
}

System.debug(arr);

for(Integer i = 0; i < arrSize; i++){
    System.debug(arr[i]);
}

Set<Integer> s1 = new Set<Integer>();
s1.add(5);
s1.add(1);
s1.add(10);
s1.add(12);

System.debug(s1);

Map<Integer, String> mpp = new Map<Integer, String>();
mpp.put(1, 'One');
mpp.put(2, 'Two');
mpp.put(3, 'Three');

System.debug(mpp);

for(Integer i = 1; i <= mpp.size(); i++){
    System.debug(mpp.get(i));
}


*/
