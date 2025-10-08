#Sentiment analysis

import torch
from transformers import DistilBertTokenizer, DistilBertForSequenceClassification
from huggingface_hub import login

# Paste your token here
login(token="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")

tokenizer = DistilBertTokenizer.from_pretrained("distilbert-base-uncased-finetuned-sst-2-english")
model = DistilBertForSequenceClassification.from_pretrained("distilbert-base-uncased-finetuned-sst-2-english")


sentences = [
    "I love this product!",
    "This is the worst experience I've had.",
    "The movie was okay, not great but not terrible either."
    "i am not feeling good due to some issue"
]

for sentence in sentences:
    inputs = tokenizer(sentence, return_tensors="pt")
    with torch.no_grad():
        logits = model(**inputs).logits
    predicted_class_id = logits.argmax().item()
    label = model.config.id2label[predicted_class_id]
    print(f"Sentence: {sentence}\nPredicted Sentiment: {label}\n")

"""  
inputs = tokenizer("Rama", return_tensors="pt")
with torch.no_grad():
    logits = model(**inputs).logits

predicted_class_id = logits.argmax().item()
model.config.id2label[predicted_class_id]
"""