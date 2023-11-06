from PIL import Image
import imagehash

# Function to compute the Average Hash (aHash) of an image
def compute_ahash(image_path):
    image = Image.open(image_path)
    ahash = imagehash.average_hash(image)
    return str(ahash)

# Function to compare the aHash values of two images
def detect_alterations(reference_image_path, target_image_path, threshold=10):
    reference_hash = compute_ahash(reference_image_path)
    target_hash = compute_ahash(target_image_path)

    hamming_distance = sum(ch1 != ch2 for ch1, ch2 in zip(reference_hash, target_hash))

    if hamming_distance <= threshold:
        return True  # Images are similar (or alterations are minor)
    else:
        return False  # Images are different (alterations detected)

if __name__ == "__main__":
    reference_image_path = "D:/University_Assignments/LP-4_Assignment/CSDF/sample_img.jpg"  # Replace with your reference image path
  # Replace with your reference image path
    target_image_path = "D:/University_Assignments/LP-4_Assignment/CSDF/sample_img_distorted.jpg"  # Replace with the image you want to check for alterations

    similarity_threshold = 10  # You can adjust this threshold as needed

    if detect_alterations(reference_image_path, target_image_path, similarity_threshold):
        print("No significant alterations detected.")
    else:
        print("Significant alterations detected.")
