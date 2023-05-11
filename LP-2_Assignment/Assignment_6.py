import random

# Define the symptoms and corresponding diagnoses
symptoms = {
    "fever": ["flu", "common cold", "malaria"],
    "cough": ["flu", "common cold", "pneumonia"],
    "headache": ["flu", "sinusitis", "migraine"],
    "fatigue": ["flu", "mononucleosis", "chronic fatigue syndrome"],
    "nausea": ["food poisoning", "stomach flu", "migraine"],
    "dizziness": ["inner ear infection", "low blood pressure", "anemia"],
    "rash": ["allergic reaction", "eczema", "measles"],
    "sore throat": ["flu", "strep throat", "tonsillitis"]
}

# Define responses for the chatbot
greetings = ["Hello! How can I assist you today?", "Welcome! How can I help?", "Hi there! What can I do for you?"]
unknown_symptom = "I'm sorry, I'm not able to diagnose that symptom."

def get_diagnosis(symptom):
    # Check if the symptom is in the symptoms dictionary
    if symptom in symptoms:
        possible_diagnoses = symptoms[symptom]
        diagnosis = random.choice(possible_diagnoses)
        return diagnosis
    else:
        return unknown_symptom

def chat():
    print(random.choice(greetings))
    print("I'm an expert in medical diagnostics. Please describe your symptoms.")
    
    while True:
        user_input = input("> ").lower()

        # Check if the user wants to quit
        if user_input == "quit":
            print("Thank you for using the chatbot. Goodbye!")
            break

        # Process the symptom and provide a diagnosis
        diagnosis = get_diagnosis(user_input)
        print(f"The possible diagnosis for {user_input} is: {diagnosis}")

        if diagnosis == unknown_symptom:
            print("I'm sorry, I'm not familiar with that symptom. Could you please describe it in more detail?")
        else:
            print("Is there anything else I can assist you with? If not, you can type 'quit' to exit.")

chat()
