import re

sentence_tags = {'\*': "li", '#': "h1", '##': "h2", '###': "h3", '####': "h4", '#####': "h5", "######": "h6"}
def parse_sent(sentence):
    for md_tag, html_tag in sentence_tags.items():
        m = re.search(f"\A{md_tag}\s", sentence)
        if m:
            return f"<{html_tag}>{sentence[m.end():]}</{html_tag}>"
    return f"<p>{sentence}</p>"

def parse(markdown):
    text = "".join([parse_sent(sent) for sent in markdown.split("\n")])
    text_tags = {"(.*)__(.*)__(.*)": "strong", "(.*)_(.*)_(.*)": "em", 
                 "(.*)(?<!(?:/li>|<ul>))(<li>.*</li>(?!(?:<li>)))(.*)": "ul"}
    for md_tag, html_tag in text_tags.items():
        m = re.match(md_tag, text)
        while m:
            text = f"{m.group(1)}<{html_tag}>{m.group(2)}</{html_tag}>{m.group(3)}"
            m = re.match(md_tag, text)
    return text