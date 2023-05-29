
1. rasa init

// configure files to define behaviour of the bot

2. rasa train

// Check whether model works correctly
3. rasa shell nlu

4. action_endpoint:
  url: "http://localhost:5055/webhook" // uncomment in file
  
5. Execute rasa run actions | rasa shell in two different terminals 
