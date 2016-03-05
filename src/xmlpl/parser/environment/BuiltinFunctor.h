#ifndef BUILTINFUNCTOR_H
#define BUILTINFUNCTOR_H

class FunctionCall;

struct BuiltinFunctorBase {
	virtual ~BuiltinFunctorBase() {}
  virtual void call(void *o, FunctionCall *) const = 0;
};

template <class T>
struct BuiltinFunctor : public BuiltinFunctorBase {
  void (T::*fpt)(FunctionCall *);   // pointer to member function

  public:
  BuiltinFunctor(void(T::*fpt)(FunctionCall *)) : fpt(fpt) {}
	virtual ~BuiltinFunctor() {}

  virtual void call(void *o, FunctionCall *fcall) const {
    (((T *)o)->*fpt)(fcall);
  }
};

#endif // BUILTINFUNCTOR_H
