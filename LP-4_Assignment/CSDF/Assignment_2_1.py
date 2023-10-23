from captcha.image import ImageCaptcha
import random
import string

# Function to generate a random CAPTCHA text


def generate_captcha_text(length=6):
    characters = string.ascii_letters + string.digits
    captcha_text = ''.join(random.choice(characters) for _ in range(length))
    return captcha_text

# Function to generate CAPTCHA image and return the text and image path


def generate_captcha():
    captcha_text = generate_captcha_text()
    image = ImageCaptcha()
    image_path = "captcha.png"
    image.write(captcha_text, image_path)
    return captcha_text, image_path


# Example usage
captcha_text, image_path = generate_captcha()
print(f"CAPTCHA Text: {captcha_text}")
print(f"CAPTCHA Image Path: {image_path}")

# Function to verify user input against the CAPTCHA text


def verify_captcha(user_input, captcha_text):
    return user_input.lower() == captcha_text.lower()


# Example usage for verification
user_input = input("Enter the CAPTCHA text: ")
if verify_captcha(user_input, captcha_text):
    print("CAPTCHA verified successfully!")
else:
    print("CAPTCHA verification failed.")
