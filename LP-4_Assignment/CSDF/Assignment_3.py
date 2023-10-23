import pytsk3


def list_files(image_path):
    img_info = pytsk3.Img_Info(image_path)
    filesystem = pytsk3.FS_Info(img_info)

    for directory_entry in filesystem.open_dir(path='/'):
        file_entry = filesystem.open_meta(directory_entry)
        file_info = file_entry.info
        print(f"File Name: {file_info.name.name.decode(errors='replace')}")
        print(f"Inode: {file_info.meta.addr}")
        print(f"File Size: {file_info.size} bytes")
        print(f"File Type: {file_info.meta.type}")
        print(f"---")


# Example usage
image_path = r'C:\Users\Admin\Desktop\disk_image.dd'
list_files(image_path)
