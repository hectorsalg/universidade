import convertapi

"""
Essa Bibliota realiza a conversão de diversas extensões de arquivos através da API Convertapi
- - -
Methods
-------
docx2jpg(path):
Converte arquivos docx para jpg

docx2pdf(path):
Converte arquivos docx para pdf

docx2png(path):
Converte arquivos docx para png

gif2png(path):
Converte arquivos gif para png

html2docx(path):
Converte arquivos html para docx

jpg2svg(path):
Converte arquivos jpg para svg

pdf2csv(path):
Converte arquivos pdf para csv

pdf2jpg(path):
Converte arquivos pdf para jpg

pdf2png(path):
Converte arquivos pdf para png

pdf2txt(path):
Converte arquivos pdf para txt
    
png2pdf(path):
Converte arquivos png para pdf

pptx2pdf(path):
Converte arquivos pptx para pdf
    
txt2jpg(path):
Converte arquivos txt para jpg

txt2pdf(path):
Converte arquivos txt para pdf

txt2png(path):
Converte arquivos txt para png

"""

def docx2jpg(path):
    """
    Converte arquivos docx para jpg

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo docx está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('jpg', { 'File': path }, from_format = 'docx').save_files('./')

def docx2pdf(path):
    """
    Converte arquivos docx para pdf

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo docx está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('pdf', { 'File': path }, from_format = 'docx').save_files('./')

def docx2png(path):
    """
    Converte arquivos docx para png

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo docx está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('png', { 'File': path }, from_format = 'docx').save_files('./')

def gif2png(path):
    """
    Converte arquivos gif para png

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo gif está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('png', { 'File': path }, from_format = 'gif').save_files('./')

def html2docx(path):
    """
    Converte arquivos html para docx

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo html está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('docx', { 'File': path }, from_format = 'html').save_files('./')

def jpg2svg(path):
    """
    Converte arquivos jpg para svg

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo jpg está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('svg', { 'File': path }, from_format = 'jpg').save_files('./')

def pdf2csv(path):
    """
    Converte arquivos pdf para csv

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo pdf está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('csv', { 'File': path, 'Delimiter': ',' }, from_format = 'pdf').save_files('./')

def pdf2jpg(path):
    """
    Converte arquivos pdf para jpg

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo pdf está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('jpg', { 'File': path }, from_format = 'pdf').save_files('./')

def pdf2png(path):
    """
    Converte arquivos pdf para png

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo pdf está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('png', { 'File': path }, from_format = 'pdf').save_files('./')

def pdf2txt(path):
    """
    Converte arquivos pdf para txt

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo pdf está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('txt', { 'File': path }, from_format = 'pdf').save_files('./')
    
def png2pdf(path):
    """
    Converte arquivos png para pdf

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo png está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('pdf', { 'File': path }, from_format = 'png').save_files('./')

def pptx2pdf(path):
    """
    Converte arquivos pptx para pdf

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo pptx está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('pdf', { 'File': path }, from_format = 'pptx').save_files('./')
    
def txt2jpg(path):
    """
    Converte arquivos txt para jpg

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo txt está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('jpg', { 'File': path }, from_format = 'txt').save_files('./')

def txt2pdf(path):
    """
    Converte arquivos txt para pdf

    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo txt está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('pdf', { 'File': path }, from_format = 'txt').save_files('./')

def txt2png(path):
    """
    Converte arquivos txt para png
    
    Parameters
    ----------
    path: str
        caminho onde o arquivo do tipo txt está localizado
    """
    convertapi.api_secret = 'wzxA1QPzyvAljkdK'
    convertapi.convert('png', { 'File': path }, from_format = 'txt').save_files('./')