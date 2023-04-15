
// Controller class for GUI visualForce page

public class CalculatorController{
    public Integer input1 { get; set; }
    public Integer input2 { get; set; }
    public Integer result { get; set; }
    
    public void add() {
        result = input1 + input2;
    }
    
    public void subtract() {
        result = input1 - input2;
    }
    
    public void multiply() {
        result = input1 * input2;
    }
    
    public void divide() {
        result = input1 / input2;
    }
}

// VisualForce page for UI

/*

<apex:page controller="CalculatorController">
    <apex:form >
        <apex:pageBlock >
            <apex:pageBlockSection columns="1">
                <apex:inputText label="Input 1" value="{!input1}"/>
                <apex:inputText label="Input 2" value="{!input2}"/>
            </apex:pageBlockSection>
        
            <apex:outputText value="Result is: {!result}" /> <br></br>
            
            <apex:commandButton action="{!add}" value="+" />
            <apex:commandButton action="{!subtract}" value="-" />
            <apex:commandButton action="{!multiply}" value="*" />
            <apex:commandButton action="{!divide}" value="/" />

        </apex:pageBlock>
    </apex:form>
</apex:page>


*/