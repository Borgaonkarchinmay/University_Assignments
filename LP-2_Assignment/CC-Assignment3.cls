
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

*/
