# Python program to automatically generate CAPTCHA and
# verify user
'''import random

# Returns true if given two strings are same
def checkCaptcha(captcha, user_captcha):
	if captcha == user_captcha:
		return True
	return False

# Generates a CAPTCHA of given length
def generateCaptcha(n):
	
	# Characters to be included
	chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
	
	# Generate n characters from above set and
	# add these characters to captcha.
	captcha = ""
	while (n):
		captcha += chrs[random.randint(1, 1000) % 62]
		n -= 1
	return captcha

# Driver code

# Generate a random CAPTCHA
captcha = generateCaptcha(9)
print(captcha)

# Ask user to enter a CAPTCHA
print("Enter above CAPTCHA:")
usr_captcha = input()

# Notify user about matching status
if (checkCaptcha(captcha, usr_captcha)):
	print("CAPTCHA Matched")
else:
	print("CAPTCHA Not Matched")'''

import random
from PIL import Image, ImageDraw, ImageFont


def generate_captcha(width, height, length):
    # Create a blank image with a yellow background
    image = Image.new('RGB', (width, height), 'yellow')
    draw = ImageDraw.Draw(image)

    # Define the characters to be used in the CAPTCHA
    characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890'

    # With a given length a random string is generated
    captcha_text = ''.join(random.sample(characters, length))

    # Define the font and its size
    font = ImageFont.truetype('arial.ttf', 72)

    # Calculate the text size and position it in the center
    t_width, t_height = draw.textsize(captcha_text, font)
    text_x = (width - t_width) / 2
    text_y = (height - t_height) / 2

    # Text is drawn in the image
    draw.text((text_x, text_y), captcha_text, font=font, fill='black')

    # Noise is added to create image distortion
    for x in range(width):
        for y in range(height):
            if random.random() < 0.1:
                draw.point((x, y), fill='black')

    # Return the generated CAPTCHA image and the corresponding text
    return image, captcha_text


width = 700  # Width of the CAPTCHA image
height = 350  # Height of the CAPTCHA image
length = 6   # Length of the CAPTCHA text

captcha_image, captcha_text = generate_captcha(width, height, length)
captcha_image.save('captcha.png')
