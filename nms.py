import numpy as np
def nms(predictions, confidence, thresh):
	start = 0
	end = predictions.shape[0]
	suppress = [False]*end
	idxs = []
	end = end-1
	while(end>=0):
		start = 0
		if(suppress[end] != True):
			while(start<end):
				if(suppress[start] != True):
					overlap = get_iou(predictions[start], predictions[end])
					if(overlap > thresh):
						if(confidence[start]>confidence[end]):
							suppress[end]= True
							idxs.append(end)
							break
						else:
							suppress[start]=True
							idxs.append(start)
				start=start+1
		end=end-1
	boxes = np.delete(predictions, idxs, 0)
	return boxes




def get_iou(box1, box2):
	iou=0.0
	x1 = max(box1[0], box2[0])
	y1 = max(box1[1], box2[1])
	x2 = min(box1[2], box2[2])
	y2 = min(box1[3], box2[3])

	inter_area = max(0, x2-x1)*max(0, y2-y1)*1.0
	area1 = (box1[2]-box1[0])*(box1[3]-box1[1])
	area2 = (box2[2]-box2[0])*(box2[3]-box2[1])
	union_area = area1+area2-inter_area*1.0

	iou = inter_area/union_area *1.0
	return iou

if __name__=='__main__':
	box1 = np.array([39, 63, 203, 112])
	box2 = np.array([54, 66, 198, 114])
	boxes = np.array([(12, 84, 140, 212),
					(24, 84, 152, 212),
					(36, 84, 164, 212),
					(12, 96, 140, 224),
					(24, 96, 152, 224),
					(24, 108, 152, 236)])
	confidence = np.array([0.8, 0.4, 0.7, 0.6, 0.7, 0.6])
	# print(boxes.shape)
	predictions = nms(boxes, confidence, 0.6)
	print(predictions)
	# print(iou(box1, box2))