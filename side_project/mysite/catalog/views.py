from django.shortcuts import render, redirect, get_object_or_404
from catalog.models import *
from django.utils import timezone
from catalog.class_form import  CheckClassName
from django.http import HttpResponse, HttpResponseRedirect
# 모델과 템플릿을 연결하는 역할
# Create your views here.


def post_list(request):
    #쿼리셋을 담은 변수
    names = layers_name.objects.values() #layer_name에서 layers 이름 전부를 불러옴
    print(layers_name)
    ClassInfoList =[]
    for name in names :
        #클래스를 가져왔는데 objects에 접근이 안됨 ㅎ.,ㅎ
        ClassName = CheckClassName.CheckName(name['name'])
        #print(ClassName.objects.values())
        #ClassInfoList.append(ClassName.objects.values())
    member = Member.objects.filter(published_date__lte=timezone.now()).order_by('published_date')
    return render(request, 'catalog/post_list.html', {'names' : names })#, 'ClassInfos':ClassInfoList})


def create(request) :
    if request.method == 'POST':

        #f 'Input' == request.POST['Input'] :
            #♥♥♥♥♥♥♥♥♥♥♥♥여기에서 request.POST로 들어오는 딕셔너리 받아서 처리하기.. 사실 딕셔너린지 아닌지도모름 ㅎ.,ㅎ
        get_names = request.POST.copy()
        print(get_names)
        #post = Input(input_shape=get_names)
        #post.save()
        return redirect('http://127.0.0.1:8000',{'na':get_names})
        #return render(request,'catalog/post_list.html',{'add_layer' : 0})
    else:
        return render(request,'catalog/post_list.html')