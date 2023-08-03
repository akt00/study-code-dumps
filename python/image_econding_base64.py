import base64
import io
import os
from PIL import Image

import numpy as np
import torch
import torchvision
from ultralytics import YOLO


def read_byte_img(fp: str):
    with open(fp, 'rb') as f:
        img = f.read()
        return base64.b64encode(img)


def from_txt(fp: str):
    with open(fp, 'r') as f:
        txt = f.read()
        # print(txt)
        bytes_txt = bytearray(txt, encoding='ascii')
        bytes_txt = base64.b64decode(bytes_txt)
        # print(len(bytes_txt))
        im = Image.open(io.BytesIO(bytes_txt))
        Image.Image.show(im)
        im.close()


def im_to_txt_workflow(fp: str):
    ret = read_byte_img(fp)
    ret = base64.b64decode(ret)
    # print(len(ret))
    # print(len(io.BytesIO(ret).read()))
    if os.path.exists(fp) is False:
        with open(fp, 'w') as f:
            f.write(ret.decode())

    from_txt(fp)


def predict(fp: str):
    dev = torch.device('cuda:0')
    model = YOLO('yolov8n.yaml').load('yolov8n.pt')
    model.to(dev)

    transform = torchvision.transforms.Compose([
        torchvision.transforms.Resize(size=(224, 224))
    ])

    with Image.open(fp) as im:
        img = np.array(im)
        img = np.transpose(img, (2, 0, 1))
        print(img.shape)

    x = torch.Tensor(img)
    x = torch.unsqueeze(x, 0)
    # x = transform(x)
    print(x.shape)
    x = x.to(dev)
    prediction = model(x)
    return prediction


def pred_torch(fp: str):
    dev = torch.device('cuda:0')
    model = torch.load(fp)
    model.to(dev)

    with Image.open(fp) as im:
        img = np.array(im)
        img = np.transpose(img, (2, 0, 1))

    x = torch.Tensor(img).to(dev)
    pred = model(x)
    print(pred)
    return pred
