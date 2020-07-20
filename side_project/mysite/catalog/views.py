from django.shortcuts import render, redirect
from catalog.models import *
from django.utils import timezone
# 모델과 템플릿을 연결하는 역할
# Create your views here.


def post_list(request):
    #쿼리셋을 담은 변수
    names = layers_name.objects.values() #layer_name에서 layers 이름 전부를 불러옴
    member = Member.objects.filter(published_date__lte=timezone.now()).order_by('published_date')
    return render(request, 'catalog/post_list.html', {'names' : names})


def create(request) :
    if request.method == 'POST':
        if 'Input' in request.POST :

            post = Input(input_shape='32')
            post.save()
        return redirect('http://127.0.0.1:8000')
        #return render(request,'catalog/post_list.html',{'add_layer' : 0})
    else:
        return render(request,'catalog/post_list.html')